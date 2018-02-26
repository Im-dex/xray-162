#include <xrCore/xrCore.h>

#include <iostream>
#include <fstream>
#include <filesystem>
#include <string_view>
#include <boost/algorithm/string.hpp>

#include <xrCore/ini_parser.h>

using namespace std::string_view_literals;
namespace fs = std::experimental::filesystem;

void printHelp() {
    std::cout << "Usage:" << std::endl << std::endl;
    std::cout << "  xrInivld [options] <path-to-ini-file> | <path-to-ini-files-dir>" << std::endl;
    std::cout << std::endl;
    std::cout << "Options:" << std::endl;
    std::cout << "  -p - print AST" << std::endl;
    std::cout << "  -r - recursive directory traversal" << std::endl;
    std::cout << "  -ext <ext> - files extension" << std::endl;
    std::cout << "  -ss - skip successfuly parsed files" << std::endl;
}

struct RecordPrinter : boost::static_visitor<> {
    void operator()(const xr::ini::ast::ValueRecord& record) const {
        std::cout << "  " << record;
    }

    void operator()(const xr::ini::ast::FullRecord& record) const {
        std::cout << "  " << record.first << " = " << record.second;
    }
};

void printRecord(const xr::ini::ast::Record& record) {
    RecordPrinter printer;
    boost::apply_visitor(printer, record);
    std::cout << std::endl;
}

void printSection(const xr::ini::ast::Section& section) {
    std::cout << "=======================================================" << std::endl;
    std::cout << "Section: " << section.header.name << std::endl;
    std::cout << "Base sections: " << boost::join(section.header.inheritance, ", ") << std::endl;
    std::cout << "Records:" << std::endl;
    for (const auto& record : section.records) {
        printRecord(record);
    }
}

bool processFile(const fs::path& path, const bool printAst) {
    [[maybe_unused]] std::error_code ec;
    if (!fs::exists(path, ec)) {
        std::cout << "File not found" << std::endl;
        return false;
    }

    std::cout << "Parsing file " << path << std::endl;

    std::ifstream stream(path);
    const auto source = std::string(std::istreambuf_iterator<char>(stream),
                                    std::istreambuf_iterator<char>());
    stream.close();
    const auto res = xr::ini::parse(source);
    if (!res) {
        std::cout << res.get_error() << std::endl;
        return false;
    }

    std::cout << "Successful!" << std::endl << std::endl;

    if (printAst) {
        std::cout << "AST:" << std::endl;
        const auto& file = res.get();
        std::cout << "  includes: " << boost::join(file.includes, ", ") << std::endl;
        for (const auto& section : file.sections) {
            printSection(section);
        }
    }

    return true;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printHelp();
        return 0;
    }

    bool printAst = false;
    bool recursive = false;
    std::string extension;
    fs::path input;

    for (size_t i = 1; i < size_t(argc); i++) {
        const std::string_view arg = argv[i];
        if (arg == "-p"sv) {
            printAst = true;
        } else if (arg == "-ext"sv) {
            i++;
            if (i >= size_t(argc)) {
                std::cout << "parameter -ext requires the value" << std::endl;
                return -1;
            }

            extension = argv[i];
        } else if (arg == "-r"sv) {
            recursive = true;
        } else {
            if (!input.empty()) {
                std::cout << "Unknown argument: " << arg << std::endl;
                return -1;
            }
            input = std::string(arg);
        }
    }

    std::vector<fs::path> files;
    [[maybe_unused]] std::error_code ec;
    if (fs::is_directory(input, ec)) {
        const auto procEntry = [&](const fs::directory_entry& entry) {
            if (fs::is_regular_file(entry.path(), ec)) {
                if (extension.empty() || (entry.path().extension().string() == extension)) {
                    files.push_back(entry.path());
                }
            }
        };

        if (recursive) {
            const auto iter = fs::recursive_directory_iterator(input, ec);
            std::for_each(begin(iter), end(iter), procEntry);
        } else {
            const auto iter = fs::directory_iterator(input, ec);
            std::for_each(begin(iter), end(iter), procEntry);
        }
    } else {
        files.push_back(std::move(input));
    }

    bool res = true;
    size_t errorCount = 0;

    for (const auto& file : files) {
        const bool processRes = processFile(file, printAst);
        if (!processRes) {
            ++errorCount;
            res = false;
        }
        std::cout << std::endl;
    }

    std::cout << files.size() << " checked / " << errorCount << " failed / "
              << (files.size() - errorCount) << " success" << std::endl;

    return (res ? 0 : -1);
}
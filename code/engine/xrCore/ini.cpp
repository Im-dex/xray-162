#include "stdafx.h"
#include "ini.h"
#include "ini_parser.h"

#include <imdexlib/buffer.hpp>
#include <imdexlib/utility.hpp>

#include <experimental/generator>

using std::experimental::generator;

namespace xr::ini {

static generator<imdex::Try<ast::File, Error>> parseRoot(ast::File rootFile,
                                                         const stdfs::path& rootPath) {
    imdex::VectorBuffer<stdfs::path, 100> pathsBuffer;
    auto& paths = pathsBuffer.vector();

    const auto addIncludes = [&paths](ast::Includes& includes, const stdfs::path& inclusivePath) {
        const auto parent = inclusivePath.parent_path();
        std::transform(std::make_move_iterator(includes.begin()),
                       std::make_move_iterator(includes.end()), std::back_inserter(paths),
                       [](std::string&& path) { return parent / std::move(path); });
    };

    addIncludes(rootFile.includes, rootPath);
    co_yield rootFile;

    while (!paths.empty()) {
        const auto path = std::move(paths.back());
        paths.pop_back();

        const auto mapper = [&](auto&& err) {
            return Error(path, IMDEX_FWD(err));
        };

        auto file = parse(path).map_error(mapper);
        file.if_success([&](auto& _) { addIncludes(_.includes, path); });
        co_yield file;
    }
}

imdex::Try<void> checkSections(const auto) {
    
}

File::LoadResult File::load(const std::string_view text, const stdfs::path& path) {
    IMDEX_UNWRAP(file, parse(text));
    imdex::ErrorChain<Error> errors;

    // TODO: dont forget to convert sections and records from ast to ini

    // sections - dup
    // records - dup
    //File file;
    Sections sections;

    // TODO: [imdex] better generator with value move support
    for (auto&& res : parseRoot(std::move(file), path)) {
        if (auto& chunk = imdex::drop_const(res); chunk.is_success()) {
            // TODO: validate records in every section
            sections.insert(std::move(chunk.get().sections));
            
        } else {
            errors.add_error(std::move(chunk).error());
        }
    }

    // TODO: validate duplicate sections

    // inheritance is allowed in readonly mode only
}

File::File(const IReader& reader, stdfs::path path)
    : flags(Flag::ReadOnly),
      path(std::move(path))
{}

} // xr::ini namespace

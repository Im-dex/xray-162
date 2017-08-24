#pragma once

#include "xrXMLParser/xrXMLParser.h"

class CUIXml : public CXml {
    int m_dbg_id;

public:
    CUIXml();
    virtual ~CUIXml();

    std::string correct_file_name(const std::string_view path, const std::string_view fn) override;
};
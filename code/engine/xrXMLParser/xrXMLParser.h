#ifndef xrXMLParserH
#define xrXMLParserH
#pragma once

#ifdef XRXMLPARSER_EXPORTS
#define XRXMLPARSER_API __declspec(dllexport)
#define PUGIXML_API __declspec(dllexport)
#else
#define XRXMLPARSER_API __declspec(dllimport)
#define PUGIXML_CLASS __declspec(dllimport)
#endif

#if !XRAY_EXCEPTIONS
#   define PUGIXML_NO_EXCEPTIONS
#endif
#define PUGIXML_NO_XPATH
#define PUGIXML_HAS_LONG_LONG
#include "pugixml.hpp"

static constexpr const char* CONFIG_PATH = "$game_config$";
static constexpr const char* UI_PATH = "ui";

class XML_NODE {
    pugi::xml_node node;
public:
    XML_NODE()
        : node()
    {}

    explicit XML_NODE(const pugi::xml_node node)
        : node(node) {}

    operator bool() const {
        return node;
    }

    bool operator== (nullptr_t) = delete;

    XML_NODE firstChild() const {
        return XML_NODE(node.first_child());
    }

    XML_NODE firstChild(const char* name) const {
        return XML_NODE(node.child(name));
    }

    XML_NODE nextSibling() const {
        return XML_NODE(node.next_sibling());
    }

    XML_NODE nextSibling(const char* name) const {
        return XML_NODE(node.next_sibling(name));
    }

    const char* textValueOr(const char* defaultValue) const {
        const auto text = node.text();
        return text ? text.get() : defaultValue;
    }

    const char* elementAttribute(const char* name) const {
        if (node.type() == pugi::node_element) {
            const auto attr = node.attribute(name);
            return attr ? attr.value() : nullptr;
        } else {
            return nullptr;
        }
    }

    const char* elementValue() const {
        if (node.type() == pugi::node_element) {
            return node.name();
        } else {
            return nullptr;
        }
    }

    const char* value() const {
        switch (node.type()) {
        case pugi::node_element:
            return node.name();
        default:
            return node.value();
        }
    }
};

struct XML_DOC {
    pugi::xml_document doc;
    pugi::xml_parse_result res;

    void clear() {
        doc.reset();
    }

    void parse(const char* data) {
        res = doc.load_string(data);
    }

    bool isError() const {
        return !res;
    }

    const char* error() const {
        return res.description();
    }

    size_t errorOffset() const {
        return res.offset;
    }

    XML_NODE firstChildElement() const {
        return XML_NODE(doc.document_element());
    }
};

class XRXMLPARSER_API CXml {
    void Load(const char* path_alias, const char* xml_filename);

public:
    string_path m_xml_file_name;
    CXml();
    virtual ~CXml();
    void ClearInternal();

    void Load(const char* path_alias, const char* path, const char* xml_filename);

    //чтение элементов
    const char* Read(const char* path, const size_t index, const char* default_str_val) const;
    const char* Read(XML_NODE start_node, const char* path, const size_t index, const char* default_str_val) const;
    const char* Read(XML_NODE node, const char* default_str_val) const;

    int ReadInt(const char* path, const size_t index, const int default_int_val) const;
    int ReadInt(XML_NODE start_node, const char* path, const size_t index, const int default_int_val) const;
    int ReadInt(XML_NODE node, const int default_int_val) const;

    float ReadFlt(const char* path, const size_t index, float default_flt_val) const;
    float ReadFlt(XML_NODE start_node, const char* path, const size_t index, float default_flt_val) const;
    float ReadFlt(XML_NODE node, float default_flt_val) const;

    const char* ReadAttrib(const char* path, const size_t index, const char* attrib, const char* default_str_val = "") const;
    const char* ReadAttrib(XML_NODE start_node, const char* path, const size_t index, const char* attrib,
                           const char* default_str_val = "") const;
    const char* ReadAttrib(XML_NODE node, const char* attrib, const char* default_str_val) const;

    int ReadAttribInt(const char* path, const size_t index, const char* attrib, const int default_int_val = 0) const;
    int ReadAttribInt(XML_NODE start_node, const char* path, const size_t index, const char* attrib,
                      const int default_int_val = 0) const;
    int ReadAttribInt(XML_NODE node, const char* attrib, const int default_int_val) const;

    float ReadAttribFlt(const char* path, const size_t index, const char* attrib, const float default_flt_val = 0.0f) const;
    float ReadAttribFlt(XML_NODE start_node, const char* path, const size_t index, const char* attrib,
                        const float default_flt_val = 0.0f) const;
    float ReadAttribFlt(XML_NODE node, const char* attrib, const float default_flt_val = 0.0f) const;

    XML_NODE SearchForAttribute(const char* path, const size_t index, const char* tag_name, const char* attrib,
                                const char* attrib_value_pattern);
    XML_NODE SearchForAttribute(XML_NODE start_node, const char* tag_name, const char* attrib,
                                const char* attrib_value_pattern) const;

    //возвращает количество узлов с заданым именем
    size_t GetNodesNum(const char* path, const size_t index, const char* tag_name) const;
    size_t GetNodesNum(XML_NODE node, const char* tag_name) const;

#ifdef DEBUG // debug & mixed
    //проверка того, что аттрибуты у тегов уникальны
    //(если не NULL, то уникальность нарушена и возврашается имя
    //повторяющегося атрибута)
    const char* CheckUniqueAttrib(XML_NODE start_node, const char* tag_name, const char* attrib_name);
#endif

    //переместиться по XML дереву
    //путь задается в форме PARENT:CHILD:CHIDLS_CHILD
    // node_index - номер, если узлов с одним именем несколько
    XML_NODE NavigateToNode(const char* path, const size_t node_index = 0) const;
    XML_NODE NavigateToNode(XML_NODE start_node, const char* path, const size_t node_index = 0) const;
    XML_NODE NavigateToNodeWithAttribute(const char* tag_name, const char* attrib_name, const char* attrib_value);

    void SetLocalRoot(XML_NODE pLocalRoot) { m_pLocalRoot = pLocalRoot; }
    XML_NODE GetLocalRoot() const { return m_pLocalRoot; }

    XML_NODE GetRoot() const { return m_root; }

protected:
    XML_NODE m_root;
    XML_NODE m_pLocalRoot;

#ifdef DEBUG // debug & mixed
    //буфферный вектор для проверки уникальность аттрибутов
    xr_vector<shared_str> m_AttribValues;
#endif
public:
    virtual shared_str correct_file_name(const char* path, const char* fn) { return fn; }

private:
    CXml(const CXml& copy);
    void operator=(const CXml& copy);

    XML_DOC m_Doc;
};

#endif // xrXMLParserH
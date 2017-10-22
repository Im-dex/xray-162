////////////////////////////////////////////////////////////////////////////
//	Module 		: debug_text_tree.h
//	Created 	: 02.04.2008
//  Modified 	: 03.04.2008
//	Author		: Lain
//	Description : Text tree for onscreen debugging
////////////////////////////////////////////////////////////////////////////

#ifndef AI_DEBUG_TEXT_TREE_H_INCLUDED
#define AI_DEBUG_TEXT_TREE_H_INCLUDED

namespace debug {

class text_tree {
public: // START INTERFACE
    text_tree(char separator = ':', int group_id_ = 0)
        : group_id(group_id_), shown(true), separator(separator) {}

    void toggle_show(int group_id);

    // finds node by first string
    text_tree* find_node(const xr_string& s1);
    // adds if cant find
    text_tree& find_or_add(const xr_string& s1);

    // add_text appends text to this node
    // add_line makes child nodes
    template <typename... Types>
    void add_text(const Types&... types) {
        // TODO: [imdex] use fold expression
        [[maybe_unused]]
        const int fold[] = { (strings.push_back(make_xrstr(types)), 0)..., 0 };
    }

    template <class Type>
    text_tree& add_line(const Type& a1) {
        text_tree& child = add_line();
        child.add_text(a1);
        return child;
    }

    template <typename Type, typename... Types>
    text_tree& add_line(const Type& a1, const Types&... as) {
        text_tree& child = add_line(a1);
        // TODO: [imdex] use fold expression
        [[maybe_unused]]
        const int fold[] = { (child.add_text(as), 0)..., 0 };
        return child;
    }

    void clear();

    template <class OutFunc>
    void output(OutFunc func, int indent = 4);

    virtual ~text_tree() { clear(); }

private: // END INTERFACE
    typedef xr_list<text_tree*> Children;
    typedef xr_vector<int> Columns;
    typedef xr_vector<xr_string> Strings;

    template <class OutFunc>
    void output(int current_indent, int indent, Columns& columns, OutFunc func);
    void prepare(int current_indent, int indent, Columns& columns);

    static void deleter(text_tree* p) { xr_delete(p); }
    int group_id;
    bool shown;
    Strings strings;
    Children children;
    char separator;
    int num_siblings;

    text_tree& add_line();
    text_tree(const text_tree& t); // no copying allowed
};

void draw_text_tree(text_tree& tree,
                    int indent, // in spaces
                    int ori_x, int ori_y,
                    int offs,        // skip offs lines
                    int column_size, // in pixels
                    int max_rows, u32 color1, u32 color2);

void log_text_tree(text_tree& tree);

#include "debug_text_tree_inline.h"

} // namespace debug

template <typename... Args>
xr_string make_xrstr(const char* format, const Args&... args) {
    char temp[4096];
    std::snprintf(temp, 4096, format, args...);
    return xr_string(temp);
}

inline xr_string make_xrstr(bool b) { return b ? "+" : "-"; }
inline xr_string make_xrstr(float f) { return make_xrstr("%f", f); }
inline xr_string make_xrstr(s32 d) { return make_xrstr("%i", d); }
inline xr_string make_xrstr(u32 d) { return make_xrstr("%u", d); }
inline xr_string make_xrstr(s64 d) { return make_xrstr("%" PRIi64, d); }
inline xr_string make_xrstr(u64 d) { return make_xrstr("%" PRIu64, d); }
inline xr_string make_xrstr(Fvector3 v) { return make_xrstr("[%f][%f][%f]", v.x, v.y, v.z); }
inline xr_string make_xrstr(const xr_string& s) { return s; }

#endif // defined(AI_DEBUG_TEXT_TREE_H_INCLUDED)

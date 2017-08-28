///////////////////////////////////////////////////////////////
// ini_table_loader.h
// ������������ �����, ������� ��������� �� ini �����
// ���������� ������� ��� ���������
///////////////////////////////////////////////////////////////

#pragma once

// T_ITEM		-	��� �������� �������
//
// T_INI_LOADER	-	��� ������ CIni_IdToIndex,
//					������ ����� ������� ���������� �������� �������
// TABLE_INDEX		-	���������� ����� �������, ����� ������ � ��� ������
//					���� �� ����� �������������� ��������� ������ � �����������
//					T_ITEM � T_INI_LOADER

#define TEMPLATE_SPECIALIZATION template <typename T_ITEM, typename T_INI_LOADER, u16 TABLE_INDEX>
#define TEMPLATE_SPECIALIZATION_D \
    template <typename T_ITEM, typename T_INI_LOADER, u16 TABLE_INDEX = 0>
#define CSIni_Table CIni_Table<T_ITEM, T_INI_LOADER, TABLE_INDEX>

TEMPLATE_SPECIALIZATION_D
class CIni_Table {
public:
    CIni_Table();
    ~CIni_Table();

    typedef xr_vector<T_ITEM> ITEM_VECTOR;
    typedef xr_vector<ITEM_VECTOR> ITEM_TABLE;

    ITEM_TABLE& table();
    void clear();
    void set_table_params(LPCSTR sect, int width = -1) {
        table_sect = sect;
        table_width = width;
    }

private:
    ITEM_TABLE* m_pTable;
    LPCSTR table_sect;
    //������ �������, ���� -1 �� ������� �������� ���������� (������ ����� ������)
    int table_width;

    //�������������� �� LPCSTR � T_ITEM

    template <typename T_CONVERT_ITEM>
    T_ITEM convert(LPCSTR) {
        static_assert(!std::is_same_v<T_CONVERT_ITEM, T_CONVERT_ITEM>,
                      "Specialization for convert in CIni_Table not found");
        NODEFAULT;
    }

    template <>
    T_ITEM convert<int>(LPCSTR str) {
        return atoi(str);
    }

    template <>
    T_ITEM convert<float>(LPCSTR str) {
        return (float)atof(str);
    }
};

/*
TEMPLATE_SPECIALIZATION
typename CSIni_Table::ITEM_TABLE* CSIni_Table::m_pTable = NULL;

//��� ������ �������
TEMPLATE_SPECIALIZATION
LPCSTR CSIni_Table::table_sect = NULL;
TEMPLATE_SPECIALIZATION
int CSIni_Table::table_width = -1;
*/

TEMPLATE_SPECIALIZATION
CSIni_Table::CIni_Table() {
    m_pTable = NULL;
    table_sect = NULL;
    table_width = -1;
}

TEMPLATE_SPECIALIZATION
CSIni_Table::~CIni_Table() { xr_delete(m_pTable); }

TEMPLATE_SPECIALIZATION
typename CSIni_Table::ITEM_TABLE& CSIni_Table::table() {
    //	T_INI_LOADER::InitIdToIndex ();

    if (m_pTable)
        return *m_pTable;

    m_pTable = xr_new<ITEM_TABLE>();

    VERIFY(table_sect);
    std::size_t table_size = T_INI_LOADER::GetMaxIndex() + 1;
    std::size_t cur_table_width = (table_width == -1) ? table_size : (std::size_t)table_width;

    m_pTable->resize(table_size);

    string64 buffer;
    CInifile::Sect& table_ini = pSettings->r_section(table_sect);

    R_ASSERT3(table_ini.Data.size() == table_size, "wrong size for table in section", table_sect);

    for (auto i = table_ini.Data.cbegin(); table_ini.Data.cend() != i; ++i) {
        T_INI_LOADER::index_type cur_index =
            T_INI_LOADER::IdToIndex((*i).first, type_max<T_INI_LOADER::index_type>);

        if (type_max<T_INI_LOADER::index_type> == cur_index)
            Debug.fatal(DEBUG_INFO, "wrong community %s in section [%s]", (*i).first, table_sect);

        (*m_pTable)[cur_index].resize(cur_table_width);
        for (std::size_t j = 0; j < cur_table_width; j++) {
            (*m_pTable)[cur_index][j] =
                convert<typename T_ITEM>(_GetItem(*(*i).second, (int)j, buffer));
        }
    }

    return *m_pTable;
}

TEMPLATE_SPECIALIZATION
void CSIni_Table::clear() { xr_delete(m_pTable); }

#undef TEMPLATE_SPECIALIZATION
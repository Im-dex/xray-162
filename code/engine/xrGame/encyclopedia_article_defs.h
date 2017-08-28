#pragma once

#include "alife_space.h"

#include "object_interfaces.h"

struct ARTICLE_DATA : public IPureSerializeObject<IReader, IWriter> {
    enum EArticleType { eEncyclopediaArticle, eJournalArticle, eTaskArticle, eInfoArticle };

    ARTICLE_DATA()
        : article_id(NULL), receive_time(0), readed(false), article_type(eEncyclopediaArticle) {}

    ARTICLE_DATA(shared_str id, ALife::_TIME_ID time, EArticleType articleType)
        : article_id(id), receive_time(time), readed(false), article_type(articleType) {}

    virtual void load(IReader& stream);
    virtual void save(IWriter&);

    ALife::_TIME_ID receive_time;
    shared_str article_id;
    bool readed;

    EArticleType article_type;
};

using ARTICLE_ID_VECTOR = xr_vector<shared_str>;
using ARTICLE_VECTOR = xr_vector<ARTICLE_DATA>;

class FindArticleByIDPred {
public:
    FindArticleByIDPred(shared_str id) { object_id = id; }
    bool operator()(const ARTICLE_DATA& item) {
        if (item.article_id == object_id)
            return true;
        else
            return false;
    }

private:
    shared_str object_id;
};

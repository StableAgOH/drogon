/**
 *
 *  Blog.cc
 *  DO NOT EDIT. This file is generated by drogon_ctl
 *
 */

#include "Blog.h"
#include "BlogTag.h"
#include "Category.h"
#include "Tag.h"
#include <drogon/utils/Utilities.h>
#include <string>

using namespace drogon;
using namespace drogon::orm;
using namespace drogon_model::sqlite3;

const std::string Blog::Cols::_id = "id";
const std::string Blog::Cols::_title = "title";
const std::string Blog::Cols::_category_id = "category_id";
const std::string Blog::primaryKeyName = "id";
const bool Blog::hasPrimaryKey = true;
const std::string Blog::tableName = "blog";

const std::vector<typename Blog::MetaData> Blog::metaData_ = {
    {"id", "int64_t", "integer auto_increment", 8, 0, 1, 0},
    {"title", "std::string", "varchar(30)", 0, 0, 0, 0},
    {"category_id", "int64_t", "integer", 8, 0, 0, 0}};

const std::string &Blog::getColumnName(size_t index) noexcept(false)
{
    assert(index < metaData_.size());
    return metaData_[index].colName_;
}

Blog::Blog(const Row &r, const ssize_t indexOffset) noexcept
{
    if (indexOffset < 0)
    {
        if (!r["id"].isNull())
        {
            id_ = std::make_shared<int64_t>(r["id"].as<int64_t>());
        }
        if (!r["title"].isNull())
        {
            title_ =
                std::make_shared<std::string>(r["title"].as<std::string>());
        }
        if (!r["category_id"].isNull())
        {
            categoryId_ =
                std::make_shared<int64_t>(r["category_id"].as<int64_t>());
        }
    }
    else
    {
        size_t offset = (size_t)indexOffset;
        if (offset + 3 > r.size())
        {
            LOG_FATAL << "Invalid SQL result for this model";
            return;
        }
        size_t index;
        index = offset + 0;
        if (!r[index].isNull())
        {
            id_ = std::make_shared<int64_t>(r[index].as<int64_t>());
        }
        index = offset + 1;
        if (!r[index].isNull())
        {
            title_ = std::make_shared<std::string>(r[index].as<std::string>());
        }
        index = offset + 2;
        if (!r[index].isNull())
        {
            categoryId_ = std::make_shared<int64_t>(r[index].as<int64_t>());
        }
    }
}

Blog::Blog(const Json::Value &pJson,
           const std::vector<std::string> &pMasqueradingVector) noexcept(false)
{
    if (pMasqueradingVector.size() != 3)
    {
        LOG_ERROR << "Bad masquerading vector";
        return;
    }
    if (!pMasqueradingVector[0].empty() &&
        pJson.isMember(pMasqueradingVector[0]))
    {
        dirtyFlag_[0] = true;
        if (!pJson[pMasqueradingVector[0]].isNull())
        {
            id_ = std::make_shared<int64_t>(
                (int64_t)pJson[pMasqueradingVector[0]].asInt64());
        }
    }
    if (!pMasqueradingVector[1].empty() &&
        pJson.isMember(pMasqueradingVector[1]))
    {
        dirtyFlag_[1] = true;
        if (!pJson[pMasqueradingVector[1]].isNull())
        {
            title_ = std::make_shared<std::string>(
                pJson[pMasqueradingVector[1]].asString());
        }
    }
    if (!pMasqueradingVector[2].empty() &&
        pJson.isMember(pMasqueradingVector[2]))
    {
        dirtyFlag_[2] = true;
        if (!pJson[pMasqueradingVector[2]].isNull())
        {
            categoryId_ = std::make_shared<int64_t>(
                (int64_t)pJson[pMasqueradingVector[2]].asInt64());
        }
    }
}

Blog::Blog(const Json::Value &pJson) noexcept(false)
{
    if (pJson.isMember("id"))
    {
        dirtyFlag_[0] = true;
        if (!pJson["id"].isNull())
        {
            id_ = std::make_shared<int64_t>((int64_t)pJson["id"].asInt64());
        }
    }
    if (pJson.isMember("title"))
    {
        dirtyFlag_[1] = true;
        if (!pJson["title"].isNull())
        {
            title_ = std::make_shared<std::string>(pJson["title"].asString());
        }
    }
    if (pJson.isMember("category_id"))
    {
        dirtyFlag_[2] = true;
        if (!pJson["category_id"].isNull())
        {
            categoryId_ = std::make_shared<int64_t>(
                (int64_t)pJson["category_id"].asInt64());
        }
    }
}

void Blog::updateByMasqueradedJson(
    const Json::Value &pJson,
    const std::vector<std::string> &pMasqueradingVector) noexcept(false)
{
    if (pMasqueradingVector.size() != 3)
    {
        LOG_ERROR << "Bad masquerading vector";
        return;
    }
    if (!pMasqueradingVector[0].empty() &&
        pJson.isMember(pMasqueradingVector[0]))
    {
        if (!pJson[pMasqueradingVector[0]].isNull())
        {
            id_ = std::make_shared<int64_t>(
                (int64_t)pJson[pMasqueradingVector[0]].asInt64());
        }
    }
    if (!pMasqueradingVector[1].empty() &&
        pJson.isMember(pMasqueradingVector[1]))
    {
        dirtyFlag_[1] = true;
        if (!pJson[pMasqueradingVector[1]].isNull())
        {
            title_ = std::make_shared<std::string>(
                pJson[pMasqueradingVector[1]].asString());
        }
    }
    if (!pMasqueradingVector[2].empty() &&
        pJson.isMember(pMasqueradingVector[2]))
    {
        dirtyFlag_[2] = true;
        if (!pJson[pMasqueradingVector[2]].isNull())
        {
            categoryId_ = std::make_shared<int64_t>(
                (int64_t)pJson[pMasqueradingVector[2]].asInt64());
        }
    }
}

void Blog::updateByJson(const Json::Value &pJson) noexcept(false)
{
    if (pJson.isMember("id"))
    {
        if (!pJson["id"].isNull())
        {
            id_ = std::make_shared<int64_t>((int64_t)pJson["id"].asInt64());
        }
    }
    if (pJson.isMember("title"))
    {
        dirtyFlag_[1] = true;
        if (!pJson["title"].isNull())
        {
            title_ = std::make_shared<std::string>(pJson["title"].asString());
        }
    }
    if (pJson.isMember("category_id"))
    {
        dirtyFlag_[2] = true;
        if (!pJson["category_id"].isNull())
        {
            categoryId_ = std::make_shared<int64_t>(
                (int64_t)pJson["category_id"].asInt64());
        }
    }
}

const int64_t &Blog::getValueOfId() const noexcept
{
    const static int64_t defaultValue = int64_t();
    if (id_)
        return *id_;
    return defaultValue;
}

const std::shared_ptr<int64_t> &Blog::getId() const noexcept
{
    return id_;
}

void Blog::setId(const int64_t &pId) noexcept
{
    id_ = std::make_shared<int64_t>(pId);
    dirtyFlag_[0] = true;
}

void Blog::setIdToNull() noexcept
{
    id_.reset();
    dirtyFlag_[0] = true;
}

const typename Blog::PrimaryKeyType &Blog::getPrimaryKey() const
{
    assert(id_);
    return *id_;
}

const std::string &Blog::getValueOfTitle() const noexcept
{
    const static std::string defaultValue = std::string();
    if (title_)
        return *title_;
    return defaultValue;
}

const std::shared_ptr<std::string> &Blog::getTitle() const noexcept
{
    return title_;
}

void Blog::setTitle(const std::string &pTitle) noexcept
{
    title_ = std::make_shared<std::string>(pTitle);
    dirtyFlag_[1] = true;
}

void Blog::setTitle(std::string &&pTitle) noexcept
{
    title_ = std::make_shared<std::string>(std::move(pTitle));
    dirtyFlag_[1] = true;
}

void Blog::setTitleToNull() noexcept
{
    title_.reset();
    dirtyFlag_[1] = true;
}

const int64_t &Blog::getValueOfCategoryId() const noexcept
{
    const static int64_t defaultValue = int64_t();
    if (categoryId_)
        return *categoryId_;
    return defaultValue;
}

const std::shared_ptr<int64_t> &Blog::getCategoryId() const noexcept
{
    return categoryId_;
}

void Blog::setCategoryId(const int64_t &pCategoryId) noexcept
{
    categoryId_ = std::make_shared<int64_t>(pCategoryId);
    dirtyFlag_[2] = true;
}

void Blog::setCategoryIdToNull() noexcept
{
    categoryId_.reset();
    dirtyFlag_[2] = true;
}

void Blog::updateId(const uint64_t id)
{
}

const std::vector<std::string> &Blog::insertColumns() noexcept
{
    static const std::vector<std::string> inCols = {"id",
                                                    "title",
                                                    "category_id"};
    return inCols;
}

void Blog::outputArgs(drogon::orm::internal::SqlBinder &binder) const
{
    if (dirtyFlag_[0])
    {
        if (getId())
        {
            binder << getValueOfId();
        }
        else
        {
            binder << nullptr;
        }
    }
    if (dirtyFlag_[1])
    {
        if (getTitle())
        {
            binder << getValueOfTitle();
        }
        else
        {
            binder << nullptr;
        }
    }
    if (dirtyFlag_[2])
    {
        if (getCategoryId())
        {
            binder << getValueOfCategoryId();
        }
        else
        {
            binder << nullptr;
        }
    }
}

const std::vector<std::string> Blog::updateColumns() const
{
    std::vector<std::string> ret;
    if (dirtyFlag_[0])
    {
        ret.push_back(getColumnName(0));
    }
    if (dirtyFlag_[1])
    {
        ret.push_back(getColumnName(1));
    }
    if (dirtyFlag_[2])
    {
        ret.push_back(getColumnName(2));
    }
    return ret;
}

void Blog::updateArgs(drogon::orm::internal::SqlBinder &binder) const
{
    if (dirtyFlag_[0])
    {
        if (getId())
        {
            binder << getValueOfId();
        }
        else
        {
            binder << nullptr;
        }
    }
    if (dirtyFlag_[1])
    {
        if (getTitle())
        {
            binder << getValueOfTitle();
        }
        else
        {
            binder << nullptr;
        }
    }
    if (dirtyFlag_[2])
    {
        if (getCategoryId())
        {
            binder << getValueOfCategoryId();
        }
        else
        {
            binder << nullptr;
        }
    }
}

Json::Value Blog::toJson() const
{
    Json::Value ret;
    if (getId())
    {
        ret["id"] = (Json::Int64)getValueOfId();
    }
    else
    {
        ret["id"] = Json::Value();
    }
    if (getTitle())
    {
        ret["title"] = getValueOfTitle();
    }
    else
    {
        ret["title"] = Json::Value();
    }
    if (getCategoryId())
    {
        ret["category_id"] = (Json::Int64)getValueOfCategoryId();
    }
    else
    {
        ret["category_id"] = Json::Value();
    }
    return ret;
}

Json::Value Blog::toMasqueradedJson(
    const std::vector<std::string> &pMasqueradingVector) const
{
    Json::Value ret;
    if (pMasqueradingVector.size() == 3)
    {
        if (!pMasqueradingVector[0].empty())
        {
            if (getId())
            {
                ret[pMasqueradingVector[0]] = (Json::Int64)getValueOfId();
            }
            else
            {
                ret[pMasqueradingVector[0]] = Json::Value();
            }
        }
        if (!pMasqueradingVector[1].empty())
        {
            if (getTitle())
            {
                ret[pMasqueradingVector[1]] = getValueOfTitle();
            }
            else
            {
                ret[pMasqueradingVector[1]] = Json::Value();
            }
        }
        if (!pMasqueradingVector[2].empty())
        {
            if (getCategoryId())
            {
                ret[pMasqueradingVector[2]] =
                    (Json::Int64)getValueOfCategoryId();
            }
            else
            {
                ret[pMasqueradingVector[2]] = Json::Value();
            }
        }
        return ret;
    }
    LOG_ERROR << "Masquerade failed";
    if (getId())
    {
        ret["id"] = (Json::Int64)getValueOfId();
    }
    else
    {
        ret["id"] = Json::Value();
    }
    if (getTitle())
    {
        ret["title"] = getValueOfTitle();
    }
    else
    {
        ret["title"] = Json::Value();
    }
    if (getCategoryId())
    {
        ret["category_id"] = (Json::Int64)getValueOfCategoryId();
    }
    else
    {
        ret["category_id"] = Json::Value();
    }
    return ret;
}

bool Blog::validateJsonForCreation(const Json::Value &pJson, std::string &err)
{
    if (pJson.isMember("id"))
    {
        if (!validJsonOfField(0, "id", pJson["id"], err, true))
            return false;
    }
    if (pJson.isMember("title"))
    {
        if (!validJsonOfField(1, "title", pJson["title"], err, true))
            return false;
    }
    if (pJson.isMember("category_id"))
    {
        if (!validJsonOfField(
                2, "category_id", pJson["category_id"], err, true))
            return false;
    }
    return true;
}

bool Blog::validateMasqueradedJsonForCreation(
    const Json::Value &pJson,
    const std::vector<std::string> &pMasqueradingVector,
    std::string &err)
{
    if (pMasqueradingVector.size() != 3)
    {
        err = "Bad masquerading vector";
        return false;
    }
    try
    {
        if (!pMasqueradingVector[0].empty())
        {
            if (pJson.isMember(pMasqueradingVector[0]))
            {
                if (!validJsonOfField(0,
                                      pMasqueradingVector[0],
                                      pJson[pMasqueradingVector[0]],
                                      err,
                                      true))
                    return false;
            }
        }
        if (!pMasqueradingVector[1].empty())
        {
            if (pJson.isMember(pMasqueradingVector[1]))
            {
                if (!validJsonOfField(1,
                                      pMasqueradingVector[1],
                                      pJson[pMasqueradingVector[1]],
                                      err,
                                      true))
                    return false;
            }
        }
        if (!pMasqueradingVector[2].empty())
        {
            if (pJson.isMember(pMasqueradingVector[2]))
            {
                if (!validJsonOfField(2,
                                      pMasqueradingVector[2],
                                      pJson[pMasqueradingVector[2]],
                                      err,
                                      true))
                    return false;
            }
        }
    }
    catch (const Json::LogicError &e)
    {
        err = e.what();
        return false;
    }
    return true;
}

bool Blog::validateJsonForUpdate(const Json::Value &pJson, std::string &err)
{
    if (pJson.isMember("id"))
    {
        if (!validJsonOfField(0, "id", pJson["id"], err, false))
            return false;
    }
    else
    {
        err =
            "The value of primary key must be set in the json object for "
            "update";
        return false;
    }
    if (pJson.isMember("title"))
    {
        if (!validJsonOfField(1, "title", pJson["title"], err, false))
            return false;
    }
    if (pJson.isMember("category_id"))
    {
        if (!validJsonOfField(
                2, "category_id", pJson["category_id"], err, false))
            return false;
    }
    return true;
}

bool Blog::validateMasqueradedJsonForUpdate(
    const Json::Value &pJson,
    const std::vector<std::string> &pMasqueradingVector,
    std::string &err)
{
    if (pMasqueradingVector.size() != 3)
    {
        err = "Bad masquerading vector";
        return false;
    }
    try
    {
        if (!pMasqueradingVector[0].empty() &&
            pJson.isMember(pMasqueradingVector[0]))
        {
            if (!validJsonOfField(0,
                                  pMasqueradingVector[0],
                                  pJson[pMasqueradingVector[0]],
                                  err,
                                  false))
                return false;
        }
        else
        {
            err =
                "The value of primary key must be set in the json object for "
                "update";
            return false;
        }
        if (!pMasqueradingVector[1].empty() &&
            pJson.isMember(pMasqueradingVector[1]))
        {
            if (!validJsonOfField(1,
                                  pMasqueradingVector[1],
                                  pJson[pMasqueradingVector[1]],
                                  err,
                                  false))
                return false;
        }
        if (!pMasqueradingVector[2].empty() &&
            pJson.isMember(pMasqueradingVector[2]))
        {
            if (!validJsonOfField(2,
                                  pMasqueradingVector[2],
                                  pJson[pMasqueradingVector[2]],
                                  err,
                                  false))
                return false;
        }
    }
    catch (const Json::LogicError &e)
    {
        err = e.what();
        return false;
    }
    return true;
}

bool Blog::validJsonOfField(size_t index,
                            const std::string &fieldName,
                            const Json::Value &pJson,
                            std::string &err,
                            bool isForCreation)
{
    switch (index)
    {
        case 0:
            if (pJson.isNull())
            {
                return true;
            }
            if (!pJson.isInt64())
            {
                err = "Type error in the " + fieldName + " field";
                return false;
            }
            break;
        case 1:
            if (pJson.isNull())
            {
                return true;
            }
            if (!pJson.isString())
            {
                err = "Type error in the " + fieldName + " field";
                return false;
            }
            break;
        case 2:
            if (pJson.isNull())
            {
                return true;
            }
            if (!pJson.isInt64())
            {
                err = "Type error in the " + fieldName + " field";
                return false;
            }
            break;
        default:
            err = "Internal error in the server";
            return false;
    }
    return true;
}

Category Blog::getCategory(const DbClientPtr &clientPtr) const
{
    const static std::string sql = "select * from category where id = ?";
    Result r(nullptr);
    {
        auto binder = *clientPtr << sql;
        binder << *categoryId_ << Mode::Blocking >>
            [&r](const Result &result) { r = result; };
        binder.exec();
    }
    if (r.size() == 0)
    {
        throw UnexpectedRows("0 rows found");
    }
    else if (r.size() > 1)
    {
        throw UnexpectedRows("Found more than one row");
    }
    return Category(r[0]);
}

void Blog::getCategory(const DbClientPtr &clientPtr,
                       const std::function<void(Category)> &rcb,
                       const ExceptionCallback &ecb) const
{
    const static std::string sql = "select * from category where id = ?";
    *clientPtr << sql << *categoryId_ >> [rcb = std::move(rcb),
                                          ecb](const Result &r) {
        if (r.size() == 0)
        {
            ecb(UnexpectedRows("0 rows found"));
        }
        else if (r.size() > 1)
        {
            ecb(UnexpectedRows("Found more than one row"));
        }
        else
        {
            rcb(Category(r[0]));
        }
    } >> ecb;
}

std::vector<std::pair<Tag, BlogTag>> Blog::getTags(
    const DbClientPtr &clientPtr) const
{
    const static std::string sql =
        "select * from tag,blog_tag where blog_tag.blog_id = ? and "
        "blog_tag.tag_id = tag.id";
    Result r(nullptr);
    {
        auto binder = *clientPtr << sql;
        binder << *id_ << Mode::Blocking >>
            [&r](const Result &result) { r = result; };
        binder.exec();
    }
    std::vector<std::pair<Tag, BlogTag>> ret;
    ret.reserve(r.size());
    for (auto const &row : r)
    {
        ret.emplace_back(
            std::pair<Tag, BlogTag>(Tag(row),
                                    BlogTag(row, Tag::getColumnNumber())));
    }
    return ret;
}

void Blog::getTags(
    const DbClientPtr &clientPtr,
    const std::function<void(std::vector<std::pair<Tag, BlogTag>>)> &rcb,
    const ExceptionCallback &ecb) const
{
    const static std::string sql =
        "select * from tag,blog_tag where blog_tag.blog_id = ? and "
        "blog_tag.tag_id = tag.id";
    *clientPtr << sql << *id_ >> [rcb = std::move(rcb)](const Result &r) {
        std::vector<std::pair<Tag, BlogTag>> ret;
        ret.reserve(r.size());
        for (auto const &row : r)
        {
            ret.emplace_back(
                std::pair<Tag, BlogTag>(Tag(row),
                                        BlogTag(row, Tag::getColumnNumber())));
        }
        rcb(ret);
    } >> ecb;
}

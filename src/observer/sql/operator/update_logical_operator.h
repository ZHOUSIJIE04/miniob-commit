#pragma once

#include<memory>
#include<vector>

#include"sql/operator/logical_operator.h"
#include"sql/parser/parse_defs.h"

class UpdateLogicalOperator : public LogicalOperator
{
public:
    UpdateLogicalOperator(Table *table, Field field, Value value);
    virtual ~UpdateLogicalOperator()=default;

    LogicalOperatorType type() const override
    {
        return LogicalOperatorType::UPDATE;
    }

    Table* table() const {
        return table_;
    }
    const Field field() const {
        return field_;
    }
    const Value value() const {
        return value_;
    }

private:
    Table *table_ = nullptr;
    Field field_;
    Value value_;
};
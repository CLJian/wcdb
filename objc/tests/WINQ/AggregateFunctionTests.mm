/*
 * Tencent is pleased to support the open source community by making
 * WCDB available.
 *
 * Copyright (C) 2017 THL A29 Limited, a Tencent company.
 * All rights reserved.
 *
 * Licensed under the BSD 3-Clause License (the "License"); you may not use
 * this file except in compliance with the License. You may obtain a copy of
 * the License at
 *
 *       https://opensource.org/licenses/BSD-3-Clause
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#import "WINQTestCase.h"
#import <WCDB/WCDB.h>

@interface AggregateFunctionTests : WINQTestCase

@end

@implementation AggregateFunctionTests {
    WCDB::Expression expression1;
    WCDB::Expression expression2;
}

- (void)setUp
{
    [super setUp];
    expression1 = 1;
    expression2 = 2;
}

- (void)test
{
    WINQAssertEqual(WCDB::AggregateFunction::avg(expression1), @"avg(1)");
    WINQAssertEqual(WCDB::AggregateFunction::count(expression1), @"count(1)");
    WINQAssertEqual(WCDB::ResultColumnAll().count(), @"count(*)");
    WINQAssertEqual(WCDB::AggregateFunction::groupConcat(expression1), @"group_concat(1)");
    WINQAssertEqual(WCDB::AggregateFunction::groupConcat(expression1, expression2), @"group_concat(1, 2)");
    WINQAssertEqual(WCDB::AggregateFunction::max(expression1), @"max(1)");
    WINQAssertEqual(WCDB::AggregateFunction::min(expression1), @"min(1)");
    WINQAssertEqual(WCDB::AggregateFunction::sum(expression1), @"sum(1)");
    WINQAssertEqual(WCDB::AggregateFunction::total(expression1), @"total(1)");
}

- (void)test_column_operable
{
    WCDB::Column column(@"testColumn");
    WINQAssertEqual(column.avg(), @"avg(testColumn)");
    WINQAssertEqual(column.count(), @"count(testColumn)");
    WINQAssertEqual(column.groupConcat(), @"group_concat(testColumn)");
    WINQAssertEqual(column.groupConcat(expression1), @"group_concat(testColumn, 1)");
    WINQAssertEqual(column.max(), @"max(testColumn)");
    WINQAssertEqual(column.min(), @"min(testColumn)");
    WINQAssertEqual(column.sum(), @"sum(testColumn)");
    WINQAssertEqual(column.total(), @"total(testColumn)");
}

- (void)test_expression_operable
{
    WCDB::Expression column = WCDB::Column(@"testColumn");
    WINQAssertEqual(column.avg(), @"avg(testColumn)");
    WINQAssertEqual(column.count(), @"count(testColumn)");
    WINQAssertEqual(column.groupConcat(), @"group_concat(testColumn)");
    WINQAssertEqual(column.groupConcat(expression1), @"group_concat(testColumn, 1)");
    WINQAssertEqual(column.max(), @"max(testColumn)");
    WINQAssertEqual(column.min(), @"min(testColumn)");
    WINQAssertEqual(column.sum(), @"sum(testColumn)");
    WINQAssertEqual(column.total(), @"total(testColumn)");
}

@end

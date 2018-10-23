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

@interface StatementAnalyzeTests : WINQTestCase

@end

@implementation StatementAnalyzeTests {
    WCDB::Schema schema;
    NSString* tableOrIndex;
}

- (void)setUp
{
    [super setUp];
    schema = @"testSchema";
    tableOrIndex = @"testTableOrIndex";
}

- (void)test_default_constructible
{
    WCDB::StatementAnalyze constructible __attribute((unused));
}

- (void)test_analyze
{
    auto testingSQL = WCDB::StatementAnalyze().analyze();
    auto testingTypes = { WCDB::SQL::Type::AnalyzeSTMT };
    IterateAssertEqual(testingSQL, testingTypes);
    WINQAssertEqual(testingSQL, @"ANALYZE");
}

- (void)test_analyze_schema
{
    auto testingSQL = WCDB::StatementAnalyze().analyzeSchema(schema);

    auto testingTypes = { WCDB::SQL::Type::AnalyzeSTMT, WCDB::SQL::Type::Schema };
    IterateAssertEqual(testingSQL, testingTypes);
    WINQAssertEqual(testingSQL, @"ANALYZE testSchema");
}

- (void)test_analyze_table_or_index
{
    auto testingSQL = WCDB::StatementAnalyze().analyzeTableOrIndex(tableOrIndex);

    auto testingTypes = { WCDB::SQL::Type::AnalyzeSTMT, WCDB::SQL::Type::Schema };
    IterateAssertEqual(testingSQL, testingTypes);
    WINQAssertEqual(testingSQL, @"ANALYZE main.testTableOrIndex");
}

- (void)test_analyze_table_or_index_without_schema
{
    auto testingSQL = WCDB::StatementAnalyze().analyzeTableOrIndex(schema, tableOrIndex);

    auto testingTypes = { WCDB::SQL::Type::AnalyzeSTMT, WCDB::SQL::Type::Schema };
    IterateAssertEqual(testingSQL, testingTypes);
    WINQAssertEqual(testingSQL, @"ANALYZE testSchema.testTableOrIndex");
}

@end

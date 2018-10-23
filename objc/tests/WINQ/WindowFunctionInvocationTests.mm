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

@interface WindowFunctionInvocationTests : WINQTestCase

@end

@implementation WindowFunctionInvocationTests {
    NSString* windowFunction;
    WCDB::Expressions expressions;
    WCDB::Filter filter;
    WCDB::WindowDef windowDef;
    NSString* window;
}

- (void)setUp
{
    [super setUp];
    windowFunction = @"testWindowFunction";
    expressions = {
        1,
        2,
    };
    filter = WCDB::Filter().where(1);
    windowDef = WCDB::WindowDef().partition(expressions);
    window = @"testWindow";
}

- (void)test_default_constructible
{
    WCDB::WindowFunctionInvocation constructible __attribute((unused));
}

- (void)test_window_function
{
    auto testingSQL = WCDB::WindowFunctionInvocation(windowFunction).invoke(expressions).over(windowDef);

    auto testingTypes = { WCDB::SQL::Type::WindowFunctionInvocation, WCDB::SQL::Type::Expression, WCDB::SQL::Type::LiteralValue, WCDB::SQL::Type::Expression, WCDB::SQL::Type::LiteralValue, WCDB::SQL::Type::WindowDef, WCDB::SQL::Type::Expression, WCDB::SQL::Type::LiteralValue, WCDB::SQL::Type::Expression, WCDB::SQL::Type::LiteralValue };
    IterateAssertEqual(testingSQL, testingTypes);
    WINQAssertEqual(testingSQL, @"testWindowFunction(1, 2) OVER(PARTITION BY 1, 2)");
}

- (void)test_window_function_without_parameters
{
    auto testingSQL = WCDB::WindowFunctionInvocation(windowFunction).invoke().over(windowDef);

    auto testingTypes = { WCDB::SQL::Type::WindowFunctionInvocation, WCDB::SQL::Type::WindowDef, WCDB::SQL::Type::Expression, WCDB::SQL::Type::LiteralValue, WCDB::SQL::Type::Expression, WCDB::SQL::Type::LiteralValue };
    IterateAssertEqual(testingSQL, testingTypes);
    WINQAssertEqual(testingSQL, @"testWindowFunction() OVER(PARTITION BY 1, 2)");
}

- (void)test_window_function_all
{
    auto testingSQL = WCDB::WindowFunctionInvocation(windowFunction).invokeAll().over(windowDef);

    auto testingTypes = { WCDB::SQL::Type::WindowFunctionInvocation, WCDB::SQL::Type::WindowDef, WCDB::SQL::Type::Expression, WCDB::SQL::Type::LiteralValue, WCDB::SQL::Type::Expression, WCDB::SQL::Type::LiteralValue };
    IterateAssertEqual(testingSQL, testingTypes);
    WINQAssertEqual(testingSQL, @"testWindowFunction(*) OVER(PARTITION BY 1, 2)");
}

- (void)test_window_function_with_filter
{
    auto testingSQL = WCDB::WindowFunctionInvocation(windowFunction).invoke(expressions).filter(filter).over(windowDef);

    auto testingTypes = { WCDB::SQL::Type::WindowFunctionInvocation, WCDB::SQL::Type::Expression, WCDB::SQL::Type::LiteralValue, WCDB::SQL::Type::Expression, WCDB::SQL::Type::LiteralValue, WCDB::SQL::Type::Filter, WCDB::SQL::Type::Expression, WCDB::SQL::Type::LiteralValue, WCDB::SQL::Type::WindowDef, WCDB::SQL::Type::Expression, WCDB::SQL::Type::LiteralValue, WCDB::SQL::Type::Expression, WCDB::SQL::Type::LiteralValue };
    IterateAssertEqual(testingSQL, testingTypes);
    WINQAssertEqual(testingSQL, @"testWindowFunction(1, 2) FILTER(WHERE 1) OVER(PARTITION BY 1, 2)");
}

- (void)test_window_function_over_window
{
    auto testingSQL = WCDB::WindowFunctionInvocation(windowFunction).invoke(expressions).over(window);

    auto testingTypes = { WCDB::SQL::Type::WindowFunctionInvocation, WCDB::SQL::Type::Expression, WCDB::SQL::Type::LiteralValue, WCDB::SQL::Type::Expression, WCDB::SQL::Type::LiteralValue };
    IterateAssertEqual(testingSQL, testingTypes);
    WINQAssertEqual(testingSQL, @"testWindowFunction(1, 2) OVER testWindow");
}

@end

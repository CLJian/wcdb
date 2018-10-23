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

#ifndef WindowFunctionInvocation_hpp
#define WindowFunctionInvocation_hpp

#include <WCDB/SQL.hpp>

namespace WCDB {

class WindowFunctionInvocation : public SQLSyntax<Syntax::WindowFunctionInvocation> {
public:
    using SQLSyntax<Syntax::WindowFunctionInvocation>::SQLSyntax;
    WindowFunctionInvocation(const SyntaxString& name);

    WindowFunctionInvocation& invoke(const Expressions& expressions);
    WindowFunctionInvocation& invoke();
    WindowFunctionInvocation& invokeAll();

    WindowFunctionInvocation& filter(const Filter& filter);

    WindowFunctionInvocation& over(const WindowDef& windowDef);
    WindowFunctionInvocation& over(const SyntaxString& window);
};

} // namespace WCDB

#endif /* WindowFunctionInvocation_hpp */

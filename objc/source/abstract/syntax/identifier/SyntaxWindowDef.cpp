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

#include <WCDB/Assertion.hpp>
#include <WCDB/Syntax.h>

namespace WCDB {

namespace Syntax {

#pragma mark - Identifier
Identifier::Type WindowDef::getType() const
{
    return type;
}

std::string WindowDef::getDescription() const
{
    std::ostringstream stream;
    bool extraSpace = false;
    if (!expressions.empty()) {
        extraSpace = true;
        stream << "PARTITION BY " << expressions;
    }
    if (!orderingTerms.empty()) {
        if (extraSpace) {
            stream << space;
        }
        stream << "ORDER BY " << orderingTerms;
    }
    if (useFrameSpec) {
        if (extraSpace) {
            stream << space;
        }
        stream << frameSpec;
    }
    return stream.str();
}

void WindowDef::iterate(const Iterator& iterator, void* parameter)
{
    Identifier::iterate(iterator, parameter);
    listIterate(expressions, iterator, parameter);
    listIterate(orderingTerms, iterator, parameter);
    if (useFrameSpec) {
        frameSpec.iterate(iterator, parameter);
    }
}

} // namespace Syntax

} // namespace WCDB

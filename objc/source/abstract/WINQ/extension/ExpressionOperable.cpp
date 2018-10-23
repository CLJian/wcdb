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

#include <WCDB/WINQ.h>

namespace WCDB {

ExpressionOperable::~ExpressionOperable()
{
}

#pragma mark - Unary
ExpressionUnaryOperable::~ExpressionUnaryOperable()
{
}

Expression ExpressionUnaryOperable::operator-() const
{
    return unaryOperate(Expression::SyntaxType::UnaryOperator::Negative);
}

Expression ExpressionUnaryOperable::operator+() const
{
    return unaryOperate(Expression::SyntaxType::UnaryOperator::Positive);
}

Expression ExpressionUnaryOperable::operator!() const
{
    return unaryOperate(Expression::SyntaxType::UnaryOperator::Not);
}

Expression ExpressionUnaryOperable::operator~() const
{
    return unaryOperate(Expression::SyntaxType::UnaryOperator::Tilde);
}

Expression ExpressionUnaryOperable::isNull() const
{
    Expression expression = unaryOperate(Expression::SyntaxType::UnaryOperator::Null);
    expression.syntax.isNot = false;
    return expression;
}

Expression ExpressionUnaryOperable::notNull() const
{
    Expression expression = unaryOperate(Expression::SyntaxType::UnaryOperator::Null);
    expression.syntax.isNot = true;
    return expression;
}

Expression
ExpressionUnaryOperable::unaryOperate(const Syntax::Expression::UnaryOperator &op) const
{
    Expression expression;
    expression.syntax.switcher = Expression::SyntaxType::Switch::UnaryOperation;
    expression.syntax.unaryOperator = op;
    expression.syntax.expressions.push_back(asExpressionOperand());
    return expression;
}

#pragma mark - Binary
ExpressionBinaryOperable::~ExpressionBinaryOperable()
{
}

Expression ExpressionBinaryOperable::concat(const Expression &operand) const
{
    return binaryOperate(operand, Expression::SyntaxType::BinaryOperator::Concatenate);
}

Expression ExpressionBinaryOperable::operator*(const Expression &operand) const
{
    return binaryOperate(operand, Expression::SyntaxType::BinaryOperator::Multiply);
}

Expression ExpressionBinaryOperable::operator/(const Expression &operand) const
{
    return binaryOperate(operand, Expression::SyntaxType::BinaryOperator::Divide);
}

Expression ExpressionBinaryOperable::operator%(const Expression &operand) const
{
    return binaryOperate(operand, Expression::SyntaxType::BinaryOperator::Modulo);
}

Expression ExpressionBinaryOperable::operator+(const Expression &operand) const
{
    return binaryOperate(operand, Expression::SyntaxType::BinaryOperator::Plus);
}

Expression ExpressionBinaryOperable::operator-(const Expression &operand) const
{
    return binaryOperate(operand, Expression::SyntaxType::BinaryOperator::Minus);
}

Expression ExpressionBinaryOperable::operator<<(const Expression &operand) const
{
    return binaryOperate(operand, Expression::SyntaxType::BinaryOperator::LeftShift);
}

Expression ExpressionBinaryOperable::operator>>(const Expression &operand) const
{
    return binaryOperate(operand, Expression::SyntaxType::BinaryOperator::RightShift);
}

Expression ExpressionBinaryOperable::operator&(const Expression &operand) const
{
    return binaryOperate(operand, Expression::SyntaxType::BinaryOperator::BitwiseAnd);
}

Expression ExpressionBinaryOperable::operator|(const Expression &operand) const
{
    return binaryOperate(operand, Expression::SyntaxType::BinaryOperator::BitwiseOr);
}

Expression ExpressionBinaryOperable::operator<(const Expression &operand) const
{
    return binaryOperate(operand, Expression::SyntaxType::BinaryOperator::Less);
}

Expression ExpressionBinaryOperable::operator<=(const Expression &operand) const
{
    return binaryOperate(operand, Expression::SyntaxType::BinaryOperator::LessOrEqual);
}

Expression ExpressionBinaryOperable::operator>(const Expression &operand) const
{
    return binaryOperate(operand, Expression::SyntaxType::BinaryOperator::Greater);
}

Expression ExpressionBinaryOperable::operator>=(const Expression &operand) const
{
    return binaryOperate(operand, Expression::SyntaxType::BinaryOperator::GreaterOrEqual);
}

Expression ExpressionBinaryOperable::operator==(const Expression &operand) const
{
    return binaryOperate(operand, Expression::SyntaxType::BinaryOperator::Equal);
}

Expression ExpressionBinaryOperable::operator!=(const Expression &operand) const
{
    return binaryOperate(operand, Expression::SyntaxType::BinaryOperator::NotEqual);
}

Expression ExpressionBinaryOperable::is(const Expression &operand) const
{
    Expression expression
    = binaryOperate(operand, Expression::SyntaxType::BinaryOperator::Is);
    expression.syntax.isNot = false;
    return expression;
}

Expression ExpressionBinaryOperable::isNot(const Expression &operand) const
{
    Expression expression
    = binaryOperate(operand, Expression::SyntaxType::BinaryOperator::Is);
    expression.syntax.isNot = true;
    return expression;
}

Expression ExpressionBinaryOperable::operator&&(const Expression &operand) const
{
    return binaryOperate(operand, Expression::SyntaxType::BinaryOperator::And);
}

Expression ExpressionBinaryOperable::operator||(const Expression &operand) const
{
    return binaryOperate(operand, Expression::SyntaxType::BinaryOperator::Or);
}

Expression ExpressionBinaryOperable::like(const Expression &operand) const
{
    Expression expression
    = binaryOperate(operand, Expression::SyntaxType::BinaryOperator::Like);
    expression.syntax.isNot = false;
    return expression;
}

Expression ExpressionBinaryOperable::glob(const Expression &operand) const
{
    Expression expression
    = binaryOperate(operand, Expression::SyntaxType::BinaryOperator::GLOB);
    expression.syntax.isNot = false;
    return expression;
}

Expression ExpressionBinaryOperable::regexp(const Expression &operand) const
{
    Expression expression
    = binaryOperate(operand, Expression::SyntaxType::BinaryOperator::RegExp);
    expression.syntax.isNot = false;
    return expression;
}

Expression ExpressionBinaryOperable::match(const Expression &operand) const
{
    Expression expression
    = binaryOperate(operand, Expression::SyntaxType::BinaryOperator::Match);
    expression.syntax.isNot = false;
    return expression;
}

Expression ExpressionBinaryOperable::notLike(const Expression &operand) const
{
    Expression expression
    = binaryOperate(operand, Expression::SyntaxType::BinaryOperator::Like);
    expression.syntax.isNot = true;
    return expression;
}

Expression ExpressionBinaryOperable::notGlob(const Expression &operand) const
{
    Expression expression
    = binaryOperate(operand, Expression::SyntaxType::BinaryOperator::GLOB);
    expression.syntax.isNot = true;
    return expression;
}

Expression ExpressionBinaryOperable::notRegexp(const Expression &operand) const
{
    Expression expression
    = binaryOperate(operand, Expression::SyntaxType::BinaryOperator::RegExp);
    expression.syntax.isNot = true;
    return expression;
}

Expression ExpressionBinaryOperable::notMatch(const Expression &operand) const
{
    Expression expression
    = binaryOperate(operand, Expression::SyntaxType::BinaryOperator::Match);
    expression.syntax.isNot = true;
    return expression;
}

Expression
ExpressionBinaryOperable::binaryOperate(const Expression &operand,
                                        const Syntax::Expression::BinaryOperator &op) const
{
    Expression expression;
    expression.syntax.switcher = Expression::SyntaxType::Switch::BinaryOperation;
    expression.syntax.binaryOperator = op;
    expression.syntax.expressions.push_back(asExpressionOperand());
    expression.syntax.expressions.push_back(operand);
    return expression;
}

#pragma mark - Between
ExpressionBetweenOperable::~ExpressionBetweenOperable()
{
}

Expression
ExpressionBetweenOperable::between(const Expression &left, const Expression &right) const
{
    Expression expression = betweenOperate(left, right);
    expression.syntax.isNot = false;
    return expression;
}

Expression ExpressionBetweenOperable::notBetween(const Expression &left,
                                                 const Expression &right) const
{
    Expression expression = betweenOperate(left, right);
    expression.syntax.isNot = true;
    return expression;
}

Expression ExpressionBetweenOperable::betweenOperate(const Expression &left,
                                                     const Expression &right) const
{
    Expression expression;
    expression.syntax.switcher = Expression::SyntaxType::Switch::Between;
    expression.syntax.expressions.push_back(asExpressionOperand());
    expression.syntax.expressions.push_back(left);
    expression.syntax.expressions.push_back(right);
    return expression;
}

#pragma mark - In
ExpressionInOperable::~ExpressionInOperable()
{
}

Expression ExpressionInOperable::in()
{
    Expression expression;
    expression.syntax.switcher = Expression::SyntaxType::Switch::In;
    expression.syntax.isNot = false;
    expression.syntax.expressions.push_back(asExpressionOperand());
    expression.syntax.inSwitcher = Expression::SyntaxType::SwitchIn::Empty;
    return expression;
}

Expression ExpressionInOperable::notIn()
{
    Expression expression = in();
    expression.syntax.isNot = true;
    return expression;
}

Expression ExpressionInOperable::inTable(const SyntaxString &table)
{
    Expression expression;
    expression.syntax.switcher = Expression::SyntaxType::Switch::In;
    expression.syntax.isNot = false;
    expression.syntax.expressions.push_back(asExpressionOperand());
    expression.syntax.inSwitcher = Expression::SyntaxType::SwitchIn::Table;
    expression.syntax.schema = Schema();
    expression.syntax.table = table;
    return expression;
}

Expression ExpressionInOperable::notInTable(const SyntaxString &table)
{
    Expression expression = inTable(table);
    expression.syntax.isNot = true;
    return expression;
}

Expression ExpressionInOperable::inTable(const Schema &schema, const SyntaxString &table)
{
    Expression expression;
    expression.syntax.switcher = Expression::SyntaxType::Switch::In;
    expression.syntax.isNot = false;
    expression.syntax.expressions.push_back(asExpressionOperand());
    expression.syntax.inSwitcher = Expression::SyntaxType::SwitchIn::Table;
    expression.syntax.schema = schema;
    expression.syntax.table = table;
    return expression;
}

Expression ExpressionInOperable::notInTable(const Schema &schema, const SyntaxString &table)
{
    Expression expression = inTable(schema, table);
    expression.syntax.isNot = true;
    return expression;
}

Expression ExpressionInOperable::in(const StatementSelect &select)
{
    Expression expression;
    expression.syntax.switcher = Expression::SyntaxType::Switch::In;
    expression.syntax.isNot = false;
    expression.syntax.expressions.push_back(asExpressionOperand());
    expression.syntax.inSwitcher = Expression::SyntaxType::SwitchIn::Select;
    expression.syntax.select = select;
    return expression;
}

Expression ExpressionInOperable::notIn(const StatementSelect &select)
{
    Expression expression = in(select);
    expression.syntax.isNot = true;
    return expression;
}

Expression ExpressionInOperable::in(const Expressions &expressions)
{
    Expression expression;
    expression.syntax.switcher = Expression::SyntaxType::Switch::In;
    expression.syntax.isNot = false;
    expression.syntax.expressions.push_back(asExpressionOperand());
    expression.syntax.inSwitcher = Expression::SyntaxType::SwitchIn::Expressions;
    expression.syntax.expressions.insert(
    expression.syntax.expressions.end(), expressions.begin(), expressions.end());
    return expression;
}

Expression ExpressionInOperable::notIn(const Expressions &expressions)
{
    Expression expression = in(expressions);
    expression.syntax.isNot = true;
    return expression;
}

Expression ExpressionInOperable::inFunction(const SyntaxString &tableFunction)
{
    Expression expression;
    expression.syntax.switcher = Expression::SyntaxType::Switch::In;
    expression.syntax.inSwitcher = Expression::SyntaxType::SwitchIn::Function;
    expression.syntax.isNot = false;
    expression.syntax.expressions.push_back(asExpressionOperand());
    expression.syntax.schema = Schema();
    expression.syntax.function = tableFunction;
    return expression;
}

Expression ExpressionInOperable::inFunction(const Schema &schema, const SyntaxString &tableFunction)
{
    Expression expression;
    expression.syntax.switcher = Expression::SyntaxType::Switch::In;
    expression.syntax.inSwitcher = Expression::SyntaxType::SwitchIn::Function;
    expression.syntax.isNot = false;
    expression.syntax.expressions.push_back(asExpressionOperand());
    expression.syntax.schema = schema;
    expression.syntax.function = tableFunction;
    return expression;
}

Expression ExpressionInOperable::notInFunction(const SyntaxString &tableFunction)
{
    Expression expression = inFunction(tableFunction);
    expression.syntax.isNot = true;
    return expression;
}

Expression ExpressionInOperable::notInFunction(const Schema &schema,
                                               const SyntaxString &tableFunction)
{
    Expression expression = inFunction(schema, tableFunction);
    expression.syntax.isNot = true;
    return expression;
}

Expression ExpressionInOperable::inFunction(const SyntaxString &tableFunction,
                                            const Expressions &parameters)
{
    Expression expression;
    expression.syntax.switcher = Expression::SyntaxType::Switch::In;
    expression.syntax.inSwitcher = Expression::SyntaxType::SwitchIn::Function;
    expression.syntax.isNot = false;
    expression.syntax.expressions.push_back(asExpressionOperand());
    expression.syntax.expressions.insert(
    expression.syntax.expressions.end(), parameters.begin(), parameters.end());
    expression.syntax.schema = Schema();
    expression.syntax.function = tableFunction;
    return expression;
}

Expression ExpressionInOperable::inFunction(const Schema &schema,
                                            const SyntaxString &tableFunction,
                                            const Expressions &parameters)
{
    Expression expression;
    expression.syntax.switcher = Expression::SyntaxType::Switch::In;
    expression.syntax.inSwitcher = Expression::SyntaxType::SwitchIn::Function;
    expression.syntax.isNot = false;
    expression.syntax.expressions.push_back(asExpressionOperand());
    expression.syntax.expressions.insert(
    expression.syntax.expressions.end(), parameters.begin(), parameters.end());
    expression.syntax.schema = schema;
    expression.syntax.function = tableFunction;
    return expression;
}

Expression ExpressionInOperable::notInFunction(const SyntaxString &tableFunction,
                                               const Expressions &parameters)
{
    Expression expression = inFunction(tableFunction, parameters);
    expression.syntax.isNot = true;
    return expression;
}

Expression ExpressionInOperable::notInFunction(const Schema &schema,
                                               const SyntaxString &tableFunction,
                                               const Expressions &parameters)
{
    Expression expression = inFunction(schema, tableFunction, parameters);
    expression.syntax.isNot = false;
    return expression;
}

#pragma mark - Collate
ExpressionCollateOperable::~ExpressionCollateOperable()
{
}

Expression ExpressionCollateOperable::collate(const SyntaxString &collation)
{
    Expression expression;
    expression.syntax.switcher = Expression::SyntaxType::Switch::Collate;
    expression.syntax.expressions.push_back(asExpressionOperand());
    expression.syntax.collation = collation;
    return expression;
}

} // namespace WCDB

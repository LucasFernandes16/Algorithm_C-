Entrada:

A entrada consiste de vários casos. A primeira linha contém c (1 ≤ c ≤ 100.000), o número de casos. A seguir, tem-se c casos, um por linha. Cada caso consiste em uma expressão aritmética ou booleana. Todas as expressões serão sintaticamente corretas.

7
1
2 + 3 * 2
( 2 - - -3 ) * 2
3 / 2
true || false == false
( true || false ) == false
true + 3


<exp>         ::= <or_exp>
<or_exp>      ::= <and_exp> [ “||” <and_exp> ]
<and_exp>     ::= <eq_exp> [ “&&” <eq_exp> ]
<eq_exp>      ::= <rel_exp> [ “==” <rel_exp> | “!=” <rel_exp> ]
<rel_exp>     ::= <add_exp> [ “<” <add_exp> | “>” <add_exp> | “<=” <add_exp> | “>=” <add_exp> ]
<add_exp>     ::= <mul_exp> [ “+” <mul_exp> | “-” <mul_exp> ]
<mul_exp>     ::= <unary_exp> [ “*” <unary_exp> | “/” <unary_exp> ]
<unary_exp>   ::= “-” <primary_exp> | <primary_exp>
<primary_exp> ::= <literal> | “(“ <exp> “)”
<literal>     ::= integer literals | boolean literals



O processamento de expressões de acordo com a gramática acima pode ser realizado a partir do algoritmo recursive descent parser. Nesse algoritmo, cria-se uma operação para cada não-terminal, cujo corpo reflete diretamente a regra correspondente na gramática. Por exemplo, veja o pseudocódigo abaixo associado ao processamento dos símbolos <exp> e <or_exp>.

Expression parse_exp() {
	return parse_or_exp();
}

Expression parse_or_exp() {
	Expression e1;
	e1 = parse_and_exp();
	if (current_token == “||”) {
		Operand op = new Operand(current_token);
read_next_token();
Expression e2;
e2 = parse_and_exp();
return new BinaryExpression(e1, op, e2);		
	} else {
		return e1;
	}
}
-------------------------------------------------------------------------------------------------------------------------------------------------------

Imprima o resultado da avaliação da expressão. Se um erro for encontrado durante a avaliação da expressão, imprima “error” (sem as aspas duplas).

1
8
-2
1
true
false
error


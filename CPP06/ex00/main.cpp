/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:26:18 by llima-ce          #+#    #+#             */
/*   Updated: 2023/03/15 18:48:24 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <limits>
#include "ScalarConverter.hpp"

#include <iostream>
#include <cassert>
 
#define assertm(exp, msg) assert(((void)msg, exp))
 

void test_ScalarConverter_find_type(){
    std::cout << "basic Tests\n";
    assertm(ScalarConverter::findType("0") == INT, "ScalarConverter::findType(\"0\") != INT");
    assertm(ScalarConverter::findType("42") == INT, "ScalarConverter::findType(\"42\") != INT");
    assertm(ScalarConverter::findType("42.0") == DOUBLE, "ScalarConverter::findType(\"42.0\") != DOUBLE");
    assertm(ScalarConverter::findType("42.0f") == FLOAT, "ScalarConverter::findType(\"42.0f\") != FLOAT");
    std::cout << "basic Tests OK\n";
    assertm(ScalarConverter::findType("a") == CHAR, "ScalarConverter::findType(\"'a'\") != CHAR");
    std::cout << "Test Invalid\n";
    assertm(ScalarConverter::findType("42.0F") == INV, "ScalarConverter::findType(\"42.0F\") != INV");
    assertm(ScalarConverter::findType("a") == CHAR, "ScalarConverter::findType(\"a\") != CHAR");
    assertm(ScalarConverter::findType("'as'") == INV, "ScalarConverter::findType(\"'as'\") != INV");
    assertm(ScalarConverter::findType("42..0f") == INV, "ScalarConverter::findType(\"42..0f\") != INV");
    assertm(ScalarConverter::findType("42.0ff") == INV, "ScalarConverter::findType(\"42.0ff\") != INV");
    assertm(ScalarConverter::findType("42.f") == INV, "ScalarConverter::findType(\"42.f\") != INV");
    assertm(ScalarConverter::findType("") == INV, "ScalarConverter::findType(\"\") != INV");
    std::cout << "Test Invalid OK\n";
    std::cout << "Test Max\n";
    assertm(ScalarConverter::findType("-42.0f") == FLOAT, "ScalarConverter::findType(\"\") != FLOAT");
    assertm(ScalarConverter::findType("-42") == INT, "ScalarConverter::findType(\"\") != INT");
    assertm(ScalarConverter::findType("nan") == DOUBLE, "ScalarConverter::findType(\"\") != DOUBLE");
    assertm(ScalarConverter::findType("+inf") == DOUBLE, "ScalarConverter::findType(\"\") != DOUBLE");
    std::cout << "Test Max OK\n";
}


int main(int argc, char* argv[]) {
    if (argc == 1) {
        try {
            test_ScalarConverter_find_type();
            std::cout << "All tests passed!\n";
        } catch (std::exception& e) {
            std::cerr << "Error: " << e.what() << '\n';
            return 1;
        }
    }
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <literal>\n";
        return 1;
    }
    ScalarConverter::convert(argv[1]);
}

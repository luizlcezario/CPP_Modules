/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:26:18 by llima-ce          #+#    #+#             */
/*   Updated: 2023/02/28 12:58:07 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <limits>
#include "Data.hpp"

#include <iostream>
#include <cassert>
 
#define assertm(exp, msg) assert(((void)msg, exp))
 

void test_data_find_type(){
    std::cout << "basic Tests\n";
    assertm(Data::findType("0") == INT, "Data::findType(\"0\") != INT");
    assertm(Data::findType("42") == INT, "Data::findType(\"42\") != INT");
    assertm(Data::findType("42.0") == DOUBLE, "Data::findType(\"42.0\") != DOUBLE");
    assertm(Data::findType("42.0f") == FLOAT, "Data::findType(\"42.0f\") != FLOAT");
    std::cout << "basic Tests OK\n";
    assertm(Data::findType("'a'") == CHAR, "Data::findType(\"'a'\") != CHAR");
    std::cout << "Test Invalid\n";
    assertm(Data::findType("42.0F") == INV, "Data::findType(\"42.0F\") != INV");
    assertm(Data::findType("a") == INV, "Data::findType(\"a\") != INV");
    assertm(Data::findType("'as'") == INV, "Data::findType(\"'as'\") != INV");
    assertm(Data::findType("42..0f") == INV, "Data::findType(\"42..0f\") != INV");
    assertm(Data::findType("42.0ff") == INV, "Data::findType(\"42.0ff\") != INV");
    assertm(Data::findType("42.f") == INV, "Data::findType(\"42.f\") != INV");
    assertm(Data::findType("") == INV, "Data::findType(\"\") != INV");
    std::cout << "Test Invalid OK\n";
    std::cout << "Test Max\n";
    assertm(Data::findType("-42.0f") == FLOAT, "Data::findType(\"\") != FLOAT");
    assertm(Data::findType("-42") == INT, "Data::findType(\"\") != INT");
    assertm(Data::findType("nan") == DOUBLE, "Data::findType(\"\") != DOUBLE");
    assertm(Data::findType("+inf") == DOUBLE, "Data::findType(\"\") != DOUBLE");
    std::cout << "Test Max OK\n";
}


int main(int argc, char* argv[]) {
    if (argc == 1) {
        try {
            test_data_find_type();
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
    Data data(argv[1]);
    std::cout << "literal: \n" << data.getLiterals() << '\n';
}

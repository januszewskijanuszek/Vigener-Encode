//
// Created by januszewskijanuszek on 03.06.2022.
//

#ifndef SZYFR_ENCODER_H
#define SZYFR_ENCODER_H

char* encodeWord(char text[], char key[]);
char* decodeWord(char encodedWord[], char key[]);
void printMatrix();

#endif //SZYFR_ENCODER_H

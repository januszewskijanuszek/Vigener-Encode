//
// Created by januszewskijanuszek on 03.06.2022.
//

#include "encoder.h"
#include <stdio.h>
#include <string.h>

int isUpper(char input){
    // If 0 than lower if 1 than upper
    if(input >= 65 && input <= 90){
        return 1;
    } else if (input >= 97 && input <= 122){
        return 0;
    }
    printf("ERROR isUpper() char out of scope");
    return 0;
}

int getIndexInAlphabet(char input){
    if(isUpper(input)){
        return input - 65;
    } else {
        return input - 97;
    }
}

char encodeChar(char firstLetter, char keyChar){
    int counter = getIndexInAlphabet(keyChar);
    int isFirstUpper = isUpper(firstLetter);
    for(int i = 0; i < counter ; i++){
        firstLetter++;
        if(firstLetter > 90 && isFirstUpper == 1){
            firstLetter = 65;
        }
        if(firstLetter > 122 && isFirstUpper == 0){
            firstLetter = 97;
        }
    }
    return firstLetter;
}

char decodeChar(char encodedChar, char keyChar){
    int counter = getIndexInAlphabet(keyChar);
    int isFirstUpper = isUpper(encodedChar);
    for(int i = 0; i < counter ; i++){
        encodedChar--;
        if(encodedChar < 65 && isFirstUpper == 1){
            encodedChar = 90;
        }
        if(encodedChar < 97 && isFirstUpper == 0){
            encodedChar = 122;
        }
    }
    return encodedChar;
}

char* encodeWord(char text[], char key[]){
    int textLength = strlen(text);
    int keyLength = strlen(key);
    int counter = 0;
    for(int i = 0 ; i < textLength ; i++){
        if(keyLength == 0){
            text[i] = encodeChar(text[i], text[counter]);
            counter++;
        } else{
            text[i] = encodeChar(text[i], key[i]);
            keyLength--;
        }
    }
    return text;
}

char* decodeWord(char encodedWord[], char key[]){
    int encodeWordLen = strlen(encodedWord);
    for(int i = 0 ; i < encodeWordLen ; i++){
        encodedWord[i] = decodeChar(encodedWord[i], key[i]);
    }
    return encodedWord;
}

void printMatrix(){
    for(int i = 0 ; i <= 25 ; i++){
        for(int j = 0 ; j <= 25 ; j++){
            printf("%c ", encodeChar(j + 65, i + 65));
        }
        printf("\n");
    }
}
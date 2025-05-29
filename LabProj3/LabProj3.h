#pragma once

#include <cstring>

int myFind(const char* targetStr, const char* subStr) {
    int count = 0; 

    for (int i = 0; i < strlen(targetStr); i++) {
        int j = 0;
        while (targetStr[i + j] == subStr[j] && subStr[j] != '\0') {
            j++;
        }
        if (subStr[j] == '\0') {
            count++;;
        }
    }

    if (count != 0) {
        return count;
    }
    else {
        return 0;
    }
}




void improveFormat(char* targetStr) {
    int i = 0;
    while (targetStr[i] != '\0') {
        if (targetStr[i] == ' ' && targetStr[i + 1] == ' ') {
            int j = i + 1;
            while (targetStr[j] != '\0') {
                targetStr[j] = targetStr[j + 1];
                j++;
            }
        }
        else {
            i++;
        }
    }
}

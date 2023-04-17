#define MAX_LENGTH 50

#include <stdio.h>
#include <stdlib.h>

typedef int KEY_TYPE;

typedef struct {
    KEY_TYPE key;
} Registration;

typedef struct {
    Registration array[MAX_LENGTH];
    int length;
} List;



List* initialize(List* list) {
    list->length = 0;
    return list;
}

int totalElementsOf(List* list) {
    return list->length;
}

void printElementsOf(List* list) {
    if(list->length > 0) {
        for (int i = 0; i < list->length; i++)
        {
            printf("Element: %i \n", list->array[i].key);
        }
    } else {
        printf("List is empty, try to add some elements to it.");
    }
}

int findElementIndexOf(List* list, KEY_TYPE key) {
    if(list->length > 0) {
        for (int i = 0; i < list->length; i++)
        {
            if(list->array[i].key == key) {
                return i;
            }
        }
    }
    return -1;
}

void addElementTo(List* list, Registration element) {
    list->array[totalElementsOf(list)] = element;
    list->length += 1;
}

bool removeElementOf(List* list, KEY_TYPE key) {
    int index = findElementIndexOf(list, key);    
    if(index == -1) {
        return false;
    }
    
    if(index == list->length - 1) {
        list->length -= 1;
        return true;
    }

    if(index <= list->length - 1) {
        
        for (int i = index; i < list->length; i++) {
            list->array[i] = list->array[i + 1];
        }

        list->length -= 1;

        return true;
    }

    return false;
}

restartList(List* list) {
    list->length = 0;
    list->array = [];
}

int main()
{
    List* list = initialize((List*) malloc(sizeof(List)));

    for (int i = 0; i < 20; i++)
    {
        Registration registration;
        registration.key = 4 * i;
        addElementTo(list, registration);
    }
    
    printf("LENGTH: %i \n", totalElementsOf(list));

    // printElementsOf(list);
    
    KEY_TYPE key = list->array[findElementIndexOf(list, 68)].key;
    
    printf("Key: %i \n", key);

    removeElementOf(list, key);

    printElementsOf(list);
    
    printf("%i", totalElementsOf(list));

    return 0;
}

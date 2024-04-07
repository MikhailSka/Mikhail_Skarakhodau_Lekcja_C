#include <stdio.h>
#include <stdlib.h>

// Struktura reprezentująca element listy
struct Node {
    int data; // Dane przechowywane w elemencie
    struct Node* next; // Wskaźnik na następny element listy
};

// Funkcja do dodawania elementu na początek listy
void add_first(struct Node** head_ref, int new_data) {
    // 1. Utworzenie nowego elementu
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    
    // 2. Ustawienie danych nowego elementu
    new_node->data = new_data;
    
    // 3. Powiązanie nowego elementu, aby wskazywał na dotychczasowy początek listy
    new_node->next = *head_ref;
    
    // 4. Ustawienie nagłówka listy jako nowy element
    *head_ref = new_node;
}

// Funkcja do wyświetlania zawartości listy
void print_list(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    // Inicjalizacja nagłówka listy jako NULL (pusta lista)
    struct Node* head = NULL;
    
    // Dodanie kilku elementów na początek listy
    add_first(&head, 3);
    add_first(&head, 5);
    add_first(&head, 7);
    
    // Wyświetlenie zawartości listy
    printf("Lista po dodaniu elementów na początek: ");
    print_list(head);
    
    return 0;
}
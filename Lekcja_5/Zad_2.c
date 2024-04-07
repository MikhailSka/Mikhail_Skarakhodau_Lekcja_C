#include <stdio.h>
#include <stdlib.h>

// Struktura reprezentująca element listy
struct Node {
    int data; // Dane przechowywane w elemencie
    struct Node* next; // Wskaźnik na następny element listy
};

// Funkcja do dodawania elementu na początek listy
void add_first(struct Node** head_ref, int new_data) {
    // Utworzenie nowego elementu
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    
    // Ustawienie danych nowego elementu
    new_node->data = new_data;
    
    // Powiązanie nowego elementu, aby wskazywał na dotychczasowy początek listy
    new_node->next = *head_ref;
    
    // Ustawienie nagłówka listy jako nowy element
    *head_ref = new_node;
}

// Funkcja do usuwania pierwszego elementu z listy
void pop(struct Node** head_ref) {
    if (*head_ref == NULL) {
        printf("Lista jest pusta, nie można usunąć elementu.\n");
        return;
    }
    
    // Zapamiętanie adresu pierwszego elementu
    struct Node* temp = *head_ref;
    
    // Przestawienie nagłówka listy na następny element
    *head_ref = (*head_ref)->next;
    
    // Zwolnienie pamięci pierwszego elementu
    free(temp);
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
    
    // Wyświetlenie zawartości listy przed usunięciem elementu
    printf("Lista przed usunięciem pierwszego elementu: ");
    print_list(head);
    
    // Usunięcie pierwszego elementu
    pop(&head);
    
    // Wyświetlenie zawartości listy po usunięciu pierwszego elementu
    printf("Lista po usunięciu pierwszego elementu: ");
    print_list(head);
    
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

// Struktura reprezentująca element listy
struct Node {
    int data; // Dane przechowywane w elemencie
    struct Node* next; // Wskaźnik na następny element listy
};

// Funkcja do dodawania elementu na koniec listy
void add_last(struct Node** head_ref, int new_data) {
    // Utworzenie nowego elementu
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    
    // Ustawienie danych nowego elementu
    new_node->data = new_data;
    new_node->next = NULL;
    
    // Jeśli lista jest pusta, nowy element staje się jej nagłówkiem
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    
    // W przeciwnym przypadku szukamy ostatniego elementu i przypisujemy nowy element do jego wskaźnika next
    struct Node* last = *head_ref;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
}

// Funkcja do usuwania ostatniego elementu z listy
void remove_last(struct Node** head_ref) {
    // Jeśli lista jest pusta, nie ma nic do usunięcia
    if (*head_ref == NULL) {
        printf("Lista jest pusta, nie można usunąć ostatniego elementu.\n");
        return;
    }
    
    // Jeśli istnieje tylko jeden element, zwalniamy pamięć i ustawiamy nagłówek jako NULL
    if ((*head_ref)->next == NULL) {
        free(*head_ref);
        *head_ref = NULL;
        return;
    }
    
    // Szukamy przedostatniego elementu
    struct Node* second_last = *head_ref;
    while (second_last->next->next != NULL) {
        second_last = second_last->next;
    }
    
    // Zwolnienie pamięci ostatniego elementu
    free(second_last->next);
    
    // Ustawienie wskaźnika next przedostatniego elementu na NULL, aby usunąć ostatni element
    second_last->next = NULL;
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
    
    // Dodanie kilku elementów na koniec listy
    add_last(&head, 3);
    add_last(&head, 5);
    add_last(&head, 7);
    
    // Wyświetlenie zawartości listy przed usunięciem ostatniego elementu
    printf("Lista przed usunięciem ostatniego elementu: ");
    print_list(head);
    
    // Usunięcie ostatniego elementu
    remove_last(&head);
    
    // Wyświetlenie zawartości listy po usunięciu ostatniego elementu
    printf("Lista po usunięciu ostatniego elementu: ");
    print_list(head);
    
    return 0;
}

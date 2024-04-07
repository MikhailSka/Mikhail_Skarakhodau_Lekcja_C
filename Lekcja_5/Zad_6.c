#include <stdio.h>
#include <stdlib.h>

// Struktura reprezentująca element listy
struct Node {
    int data; // Dane przechowywane w elemencie
    struct Node* next; // Wskaźnik na następny element listy
};

// Funkcja do dodawania elementu na konkretny indeks
void insert_at_index(struct Node** head_ref, int index, int new_data) {
    // Utworzenie nowego elementu
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    
    // Ustawienie danych nowego elementu
    new_node->data = new_data;
    
    // Jeśli indeks jest 0 lub lista jest pusta, nowy element staje się nagłówkiem
    if (index == 0 || *head_ref == NULL) {
        new_node->next = *head_ref;
        *head_ref = new_node;
        return;
    }
    
    // Szukamy elementu przed miejscem, gdzie chcemy wstawić nowy element
    struct Node* prev_node = *head_ref;
    for (int i = 0; prev_node != NULL && i < index - 1; i++) {
        prev_node = prev_node->next;
    }
    
    // Jeśli indeks jest większy niż długość listy
    if (prev_node == NULL) {
        printf("Podany indeks przekracza długość listy.\n");
        return;
    }
    
    // Wstawienie nowego elementu między prev_node a jego następnikiem
    new_node->next = prev_node->next;
    prev_node->next = new_node;
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
    insert_at_index(&head, 0, 3);
    insert_at_index(&head, 1, 5);
    insert_at_index(&head, 2, 7);
    
    // Wyświetlenie zawartości listy przed wstawieniem elementu na określonym indeksie
    printf("Lista przed wstawieniem elementu na określonym indeksie: ");
    print_list(head);
    
    // Wstawienie elementu o wartości 10 na indeksie 1
    insert_at_index(&head, 1, 10);
    
    // Wyświetlenie zawartości listy po wstawieniu elementu na określonym indeksie
    printf("Lista po wstawieniu elementu na określonym indeksie: ");
    print_list(head);
    
    return 0;
}

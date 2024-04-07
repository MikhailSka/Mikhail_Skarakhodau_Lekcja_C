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

// Funkcja do usuwania pierwszego elementu z listy o określonej wartości
void remove_by_value(struct Node** head_ref, int key) {
    // Jeśli lista jest pusta, nie ma nic do usunięcia
    if (*head_ref == NULL) {
        printf("Lista jest pusta, nie można usunąć elementu.\n");
        return;
    }
    
    // Jeśli pierwszy element ma wartość klucza
    if ((*head_ref)->data == key) {
        struct Node* temp = *head_ref;
        *head_ref = (*head_ref)->next;
        free(temp);
        return;
    }
    
    // Szukamy elementu przed elementem o wartości klucza
    struct Node* prev_node = *head_ref;
    while (prev_node->next != NULL && prev_node->next->data != key) {
        prev_node = prev_node->next;
    }
    
    // Jeśli nie znaleziono elementu o wartości klucza
    if (prev_node->next == NULL) {
        printf("Nie znaleziono elementu o wartości %d.\n", key);
        return;
    }
    
    // Zapamiętujemy element o wartości klucza i przestawiamy wskaźnik next poprzedniego elementu
    struct Node* temp = prev_node->next;
    prev_node->next = prev_node->next->next;
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
    
    // Dodanie kilku elementów na koniec listy
    add_last(&head, 3);
    add_last(&head, 5);
    add_last(&head, 7);
    
    // Wyświetlenie zawartości listy przed usunięciem elementu o określonej wartości
    printf("Lista przed usunięciem elementu o określonej wartości: ");
    print_list(head);
    
    // Usunięcie pierwszego elementu o wartości 5
    remove_by_value(&head, 5);
    
    // Wyświetlenie zawartości listy po usunięciu elementu o określonej wartości
    printf("Lista po usunięciu elementu o określonej wartości: ");
    print_list(head);
    
    return 0;
}

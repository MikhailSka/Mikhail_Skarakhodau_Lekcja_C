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

// Funkcja do usuwania elementu z listy według indeksu
void remove_by_index(struct Node** head_ref, int index) {
    // Jeśli lista jest pusta, nie ma nic do usunięcia
    if (*head_ref == NULL) {
        printf("Lista jest pusta, nie można usunąć elementu.\n");
        return;
    }
    
    // Jeśli usuwamy pierwszy element
    if (index == 0) {
        struct Node* temp = *head_ref;
        *head_ref = (*head_ref)->next;
        free(temp);
        return;
    }
    
    // Szukamy elementu przed elementem, który chcemy usunąć
    struct Node* prev_node = *head_ref;
    for (int i = 0; prev_node != NULL && i < index - 1; i++) {
        prev_node = prev_node->next;
    }
    
    // Jeśli indeks jest większy niż długość listy
    if (prev_node == NULL || prev_node->next == NULL) {
        printf("Podany indeks przekracza długość listy.\n");
        return;
    }
    
    // Zapamiętujemy element, który chcemy usunąć i przestawiamy wskaźnik next poprzedniego elementu
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
    
    // Wyświetlenie zawartości listy przed usunięciem konkretnego elementu
    printf("Lista przed usunięciem konkretnego elementu: ");
    print_list(head);
    
    // Usunięcie elementu na podstawie indeksu
    remove_by_index(&head, 1); // Usunięcie elementu o indeksie 1
    
    // Wyświetlenie zawartości listy po usunięciu konkretnego elementu
    printf("Lista po usunięciu konkretnego elementu: ");
    print_list(head);
    
    return 0;
}

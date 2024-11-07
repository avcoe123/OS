#!/bin/bash

createAddressBook() {
    if [ -e addressbook.txt ]; then
        echo "Address Book already exists."
    else
        touch addressbook.txt
        echo "Address Book created."
    fi
}

insertRecord() {
    while true; do
        echo "Enter record in format: 'last name, first name, email, phone number'"
        echo "To quit, enter 'q'"
        read record

        if [[ "$record" == "q" ]]; then
            break
        fi

        echo "$record" >> addressbook.txt
        echo "Record added."
    done
}

viewRecord() {
    while true; do
        echo "Enter last name to search (case-sensitive)"
        echo "To quit, enter 'q'"
        read lastName

        if [[ "$lastName" == "q" ]]; then
            break
        fi

        grep "^$lastName," addressbook.txt
    done
}



searchRecord() {
    while true; do
        echo "Enter search term (last name, first name, email, or phone number)"
        echo "To quit, enter 'q'"
        read searchTerm

        if [[ "$searchTerm" == "q" ]]; then
            break
        fi

        grep "$searchTerm" addressbook.txt
    done
}

while true; do
    echo "Address Book Menu"
    echo "1. Create Address Book"
    echo "2. Insert Record"
    echo "3. View Records"
    echo "4. Search Records"
    echo "5. Exit"
    read choice

    case $choice in
        1) createAddressBook ;;
        2) insertRecord ;;
        3) viewRecord ;;
        4) searchRecord ;;
        5) exit 0 ;;
        *) echo "Invalid choice. Please try again." ;;
    esac
done
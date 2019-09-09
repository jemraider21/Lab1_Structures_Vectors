This lab simulates a database to store animal types and animal type count. A programmer defined data structure and a vector are used for data storage(required)

Steps:
1. Create a programmer defined data structure to store the animal type and animal count
2. Create an empty vector(zero elements, no size) to store the data for one to five animals
    Note: You are not allowed to use array notation to add new elements to the vector
3. Input the types(s) and counts of one to five animals. Input should cease at the fifth entry, or when the user enters any form of the word none before five entries have been made. Use a programmer defined function for input
    Note:
        *  The animal types should be able to accept one or more words for the animal type. Assume at least one animal will be entered
        * All variables should be initialized
        * All data must be validated
        * Data entry for animal counts is not allowed without a corresponding animal type
        * Your program should accept any version of the word none: Uppercase, lowercase, or mixed case. Convert the entry to lowercase before testing. You will need to include the cctype library for this. To accomplished this create a function called toLowerCase based on the following prototype: string toLowerCase(string)
4. Display a list of animal types and counts. Each animal type must be a corresponding count. Use a programmer defined function to display the list
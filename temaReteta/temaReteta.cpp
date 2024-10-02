#include <iostream>
#include<string>
using namespace std;

class Recipe
{
private:
    string name;
    string ingredients;
    string instructions;
    string review;

public:

    Recipe(string name, string ingredients, string instructions, string review)
        : name(name), ingredients(ingredients), instructions(instructions), review(review) {}

    void setName(string name)
    {
        this->name = name;
    }
    
    void setIngredients(string ingredients)
    {
        this->ingredients = ingredients;
    }

    void setInstructions(string instructions)
    {
        this->instructions = instructions;
    }

    void setReview(string review)
    {
        this->review = review;
    }

    void displayRecipe()
    {
        cout << name << endl;
        cout << "Ingredients: " << ingredients<< endl;
        cout << "Instructions: " << instructions << endl;
        cout << "Review: " << review << endl;

    }

    string getName() const
    {
        return name;
    }

    string getIngredients() const
    {
        return ingredients;
    }

    string getInstructions() const
    {
        return instructions;
    }

    string getReview() const
    {
        return review;
    }

};

int main()
{
    Recipe r1("Mujdei", "usturoi, apa, sare", "Zdrobim usturoiul si il amestecam cu apa si sare", "Excelent!");
    r1.setReview("Nemaipomenit!");
    r1.displayRecipe();
}


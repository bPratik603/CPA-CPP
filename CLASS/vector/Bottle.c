#include <stdio.h>
#include <stdlib.h>

struct Bottle
{
    char* name;
    float price;
    int size;
    char* pattern;
    char* material;
    char* colour;
    int capacity;
    char* brand;
    int item_weight;
    struct Date
    {
        int date;
        char* month;
        int year;
    }first_available_date;
    char* manufacturer;
    char* country_of_origin;
    struct Dimension
    {
        float length;
        float width;
        float height;
    }dimension_of_product;
    char* item_model_number;
    char* included_components;
    int net_quantity;
}new_bottle = {
        "Borosil Stainless Steel HYDRA BOLT",
        1220,
        1000,
        "Flask",
        "Stainless Steel",
        "Silver",
        1,
        "Borosil",
        550,
        {
            2,
            "August",
            2019
        },
        "Marketed & Imported By - Borosil Limited",
        "India",
        {
            9,
            9,
            32.5
        },
        "BRL_ISFGBO1000S_SIR",
        "1 Stainless Steel Bottle",
        1
    };

    int main(void)
    {
        printf("Name                :               %s\n", new_bottle.name);
        printf("Price               :               %f\n", new_bottle.price);
        printf("Size                :               %d\n", new_bottle.size);
        printf("Pattern             :               %s\n", new_bottle.pattern);
        printf("Material            :               %s\n", new_bottle.material);
        printf("Colour              :               %s\n", new_bottle.colour);
        printf("Capacity            :               %d\n", new_bottle.capacity);
        printf("Brand               :               %s\n", new_bottle.brand);
        printf("Item weight         :               %d\n", new_bottle.item_weight);
        printf("First available date:               %d %s %d\n", new_bottle.first_available_date.date, new_bottle.first_available_date.month, new_bottle.first_available_date.year);
        printf("Manufacturer        :               %s\n", new_bottle.manufacturer);
        printf("Country of origin   :               %s\n", new_bottle.country_of_origin);
        printf("Dimensions          :               %f * %f * %f\n", new_bottle.dimension_of_product.length, new_bottle.dimension_of_product.width, new_bottle.dimension_of_product.height);
        printf("Item Model number   :               %s\n", new_bottle.item_model_number);
        printf("Included Components :               %s\n", new_bottle.included_components);
        printf("Net quantity        :               %d\n", new_bottle.net_quantity);
    }
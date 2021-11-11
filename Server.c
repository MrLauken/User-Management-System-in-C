#include <stdio.h>


int main () {
    int client = mongoc_client_new ("mongodb+srv://SharedUser:StyggeBarnHarMangeNavn@cluster0.z1hmd.mongodb.net/myFirstDatabase?retryWrites=true&w=majority");
    int db = mongoc_client_get_database (client, "test");




}
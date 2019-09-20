//
// Created by esteban on 18/09/19.
//

#include "donkeyUI.h"

static void get_Input(GtkWidget *widget)
{
    g_print("%s\n", gtk_entry_get_text(GTK_ENTRY(entry)));
    const gchar *entry_text;
    entry_text = gtk_entry_get_text (GTK_ENTRY (entry));
    printf ("Entry contents: %s\n", entry_text);
}

int init_Donkey(int argc, char *argv[]){
    //Aqui lo que hacemos es cargar el motor grafico
    gtk_init(&argc, &argv);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(window), 800, 600);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    //Aqui lo que sucede es crear un layout como container  para las cosas que se pondran en la ventana
    layout = gtk_layout_new(NULL, NULL);
    gtk_container_add(GTK_CONTAINER (window), layout);
    gtk_widget_show(layout);
    //Aqui lo que hacemos es crear los botones y el entry.Ademas de eso creamos  la imagen con el fondo  establecido
    button = gtk_button_new_with_label ("Conectarse Como Jugador");
    button2 = gtk_button_new_with_label ("Conectarse Como Observador");
    entry= gtk_entry_new ();
    image = gtk_image_new_from_file("../img/background2.png");
    //Aqui asociamos un metodo con el boton cuando se realiza en el la accion de clicked
    g_signal_connect (button, "clicked", G_CALLBACK (get_Input), NULL);
    //Aqui lo que hacemos es  pegar todas las cosas en la ventana con sus respectivas cordenadas
    gtk_layout_put(GTK_LAYOUT(layout), image, 0, 0);
    gtk_entry_set_max_length (GTK_ENTRY (entry),0);
    gtk_layout_put(GTK_LAYOUT(layout), button2, 130, 445);
    gtk_layout_put(GTK_LAYOUT(layout), button, 140, 390);
    gtk_layout_put(GTK_LAYOUT(layout), entry, 475, 290);
    gtk_widget_set_size_request(button, 80, 35);
    gtk_widget_set_size_request(button2, 80, 35);
/*
      gtk_layout_put(GTK_LAYOUT(layout), button2, 130, 445);
      gtk_layout_put(GTK_LAYOUT(layout), button, 140, 390);
      gtk_layout_put(GTK_LAYOUT(layout), entry, 475, 290);
      */

    g_signal_connect_swapped(G_OBJECT(window), "destroy",
                             G_CALLBACK(gtk_main_quit), NULL);

    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}
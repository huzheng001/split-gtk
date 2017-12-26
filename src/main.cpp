/*
 * This file is part of split-gtk.
 *
 * split-gtk is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * split-gtk is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with split-gtk.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifdef HAVE_CONFIG_H
#  include "config.h"
#endif


#include <glib/gi18n.h>
#include <gtk/gtk.h>







static gboolean on_delete_event(GtkWidget * window, GdkEvent *event , gpointer data)
{
	gtk_main_quit();
	return FALSE;
}

static void create_window()
{
	GtkWidget *main_window;
	main_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_position (GTK_WINDOW (main_window), GTK_WIN_POS_CENTER);
	gtk_window_set_title(GTK_WINDOW (main_window), _("split-gtk"));
	gtk_window_set_default_size(GTK_WINDOW (main_window), 410, 470);
	gtk_container_set_border_width (GTK_CONTAINER (main_window), 5);
	g_signal_connect (G_OBJECT (main_window), "delete_event", G_CALLBACK (on_delete_event), NULL);

	GtkWidget *main_vbox;
	main_vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 8);
	gtk_container_add(GTK_CONTAINER(main_window), main_vbox);

	GtkWidget *hbox1 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10);
	gtk_box_pack_start (GTK_BOX (main_vbox), hbox1, TRUE, TRUE, 2);

	GtkWidget *radio1 = gtk_radio_button_new (NULL);
	gtk_box_pack_start (GTK_BOX (hbox1), radio1, TRUE, TRUE, 2);
	GtkWidget *entry = gtk_entry_new();
	gtk_container_add (GTK_CONTAINER (radio1), entry);

	GtkWidget *radio2 = gtk_radio_button_new_with_label_from_widget (GTK_RADIO_BUTTON (radio1), "800M");
	gtk_box_pack_start (GTK_BOX (hbox1), radio2, TRUE, TRUE, 2);
	GtkWidget *radio3 = gtk_radio_button_new_with_label_from_widget (GTK_RADIO_BUTTON (radio1), "1G");
	gtk_box_pack_start (GTK_BOX (hbox1), radio3, TRUE, TRUE, 2);
	GtkWidget *radio4 = gtk_radio_button_new_with_label_from_widget (GTK_RADIO_BUTTON (radio1), "2G");
	gtk_box_pack_start (GTK_BOX (hbox1), radio4, TRUE, TRUE, 2);
	GtkWidget *radio5 = gtk_radio_button_new_with_label_from_widget (GTK_RADIO_BUTTON (radio1), "4G");
	gtk_box_pack_start (GTK_BOX (hbox1), radio5, TRUE, TRUE, 2);


	GtkWidget *hbox2 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10);
	gtk_box_pack_start (GTK_BOX (main_vbox), hbox2, TRUE, TRUE, 2);

	GtkWidget *radio_a1 = gtk_radio_button_new_with_label(NULL, "file.1 file.2 file.3 file.4 ....");
	gtk_box_pack_start (GTK_BOX (hbox2), radio_a1, TRUE, TRUE, 2);

	GtkWidget *radio_a2 = gtk_radio_button_new_with_label_from_widget (GTK_RADIO_BUTTON (radio_a1), "xaa xab xac xad xae xaf ....");
	gtk_box_pack_start (GTK_BOX (hbox2), radio_a2, TRUE, TRUE, 2);

	GtkWidget *button1 = gtk_button_new_with_mnemonic(_("_Split"));
	gtk_box_pack_start (GTK_BOX (main_vbox), button1, TRUE, TRUE, 2);


	gtk_widget_show_all(main_window);
}

int main(int argc,char **argv)
{
	gtk_init(&argc, &argv);
	create_window();
	gtk_main();
	return 0;
}

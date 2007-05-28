/*
 * Copyright (C) 2004-2007 Nikolay Pultsin <geometer@mawhrin.net>
 * Copyright (C) 2005 Mikhail Sobolev <mss@mawhrin.net>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA.
 */

#ifndef __ZLGTKDIALOGCONTENT_H__
#define __ZLGTKDIALOGCONTENT_H__

#include <gtk/gtktable.h>

#include <ZLDialogContent.h>

class ZLGtkDialogContent : public ZLDialogContent {

public:
	ZLGtkDialogContent(const ZLResource &resource);
	~ZLGtkDialogContent();

	void addOption(const std::string &name, const std::string &tooltip, ZLOptionEntry *option);
	void addOptions(const std::string &name0, const std::string &tooltip0, ZLOptionEntry *option0,
									const std::string &name1, const std::string &tooltip1, ZLOptionEntry *option1);


	GtkWidget *widget() { return GTK_WIDGET(myTable); }

	void addItem(GtkWidget *what, int row, int fromColumn, int toColumn);

private:
	int addRow();
	void createViewByEntry(const std::string &name, const std::string &tooltip, ZLOptionEntry *option, int row, int fromColumn, int toColumn);

private:
	GtkTable *myTable;
	gint myRowCounter;
};

#endif /* __ZLGTKDIALOGCONTENT_H__ */

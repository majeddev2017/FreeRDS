/*
   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

   xrdp: A Remote Desktop Protocol server.
   Copyright (C) Jay Sorg 2004-2005

   main login window and login help window

*/

#include "xrdp.h"

/*****************************************************************************/
/* all login help screen events go here */
int xrdp_wm_login_help_notify(struct xrdp_bitmap* wnd,
                              struct xrdp_bitmap* sender,
                              int msg, long param1, long param2)
{
  struct xrdp_painter* p;

  if (wnd == 0)
  {
    return 0;
  }
  if (sender == 0)
  {
    return 0;
  }
  if (wnd->owner == 0)
  {
    return 0;
  }
  if (msg == 1) /* click */
  {
    if (sender->id == 1) /* ok button */
    {
      if (sender->owner->notify != 0)
      {
        wnd->owner->notify(wnd->owner, wnd, 100, 1, 0); /* ok */
      }
    }
  }
  else if (msg == WM_PAINT) /* 3 */
  {
    p = (struct xrdp_painter*)param1;
    if (p != 0)
    {
      p->font->color = wnd->wm->black;
      xrdp_painter_draw_text(p, wnd, 10, 30, "You must be authenticated \
before using this");
      xrdp_painter_draw_text(p, wnd, 10, 46, "session.");
      xrdp_painter_draw_text(p, wnd, 10, 78, "Enter a valid username in \
the username edit box.");
      xrdp_painter_draw_text(p, wnd, 10, 94, "Enter the password in \
the password edit box.");
      xrdp_painter_draw_text(p, wnd, 10, 110, "Both the username and \
password are case");
      xrdp_painter_draw_text(p, wnd, 10, 126, "sensitive.");
      xrdp_painter_draw_text(p, wnd, 10, 158, "Contact your system \
administrator if you are");
      xrdp_painter_draw_text(p, wnd, 10, 174, "having problems \
logging on.");
    }
  }
  return 0;
}

/*****************************************************************************/
int xrdp_wm_popup_notify(struct xrdp_bitmap* wnd,
                         struct xrdp_bitmap* sender,
                         int msg, int param1, int param2)
{
  return 0;
}

/*****************************************************************************/
int xrdp_wm_setup_mod(struct xrdp_wm* self,
                      struct xrdp_mod_data* mod_data)
{
  if (self == 0)
  {
    return 1;
  }
  if (self->mod_handle == 0)
  {
    self->mod_handle = g_load_library(mod_data->lib);
    if (self->mod_handle != 0)
    {
      self->mod_init = (struct xrdp_mod* (*)(void))
                g_get_proc_address(self->mod_handle, "mod_init");
      self->mod_exit = (int (*)(struct xrdp_mod*))
                g_get_proc_address(self->mod_handle, "mod_exit");
      if (self->mod_init != 0 && self->mod_exit != 0)
      {
        self->mod = self->mod_init();
      }
    }
    if (self->mod != 0)
    {
      self->mod->wm = (long)self;
      self->mod->server_begin_update = server_begin_update;
      self->mod->server_end_update = server_end_update;
      self->mod->server_fill_rect = server_fill_rect;
      self->mod->server_screen_blt = server_screen_blt;
      self->mod->server_paint_rect = server_paint_rect;
      self->mod->server_set_pointer = server_set_pointer;
      self->mod->server_palette = server_palette;
      self->mod->server_msg = server_msg;
      self->mod->server_is_term = server_is_term;
    }
  }
  /* id self->mod is null, there must be a problem */
  if (self->mod == 0)
  {
    DEBUG(("problem loading lib in xrdp_wm_setup_mod\n\r"));
    return 1;
  }
  return 0;
}

/*****************************************************************************/
int xrdp_wm_delete_all_childs(struct xrdp_wm* self)
{
  int i;
  struct xrdp_bitmap* b;

  for (i = self->screen->child_list->count - 1; i >= 0; i--)
  {
    b = (struct xrdp_bitmap*)xrdp_list_get_item(self->screen->child_list, i);
    xrdp_bitmap_delete(b);
  }
  xrdp_bitmap_invalidate(self->screen, 0);
  return 0;
}

/*****************************************************************************/
int set_mod_data_item(struct xrdp_mod_data* mod, char* name, char* value)
{
  int index;

  for (index = 0; index < mod->names->count; index++)
  {
    if (g_strcmp(name, (char*)xrdp_list_get_item(mod->names, index)) == 0)
    {
      xrdp_list_remove_item(mod->values, index);
      xrdp_list_insert_item(mod->values, index, (long)g_strdup(value));
    }
  }
  return 0;
}

/*****************************************************************************/
int xrdp_wm_help_clicked(struct xrdp_bitmap* wnd)
{
  struct xrdp_bitmap* help;
  struct xrdp_bitmap* but;

  /* create help screen */
  help = xrdp_bitmap_create(300, 300, wnd->wm->screen->bpp,
                            WND_TYPE_WND, wnd->wm);
  xrdp_list_insert_item(wnd->wm->screen->child_list, 0, (long)help);
  help->parent = wnd->wm->screen;
  help->owner = wnd;
  wnd->modal_dialog = help;
  help->bg_color = wnd->wm->grey;
  help->left = wnd->wm->screen->width / 2 - help->width / 2;
  help->top = wnd->wm->screen->height / 2 - help->height / 2;
  help->notify = xrdp_wm_login_help_notify;
  set_string(&help->caption1, "Login help");
  /* ok button */
  but = xrdp_bitmap_create(60, 25, wnd->wm->screen->bpp,
                           WND_TYPE_BUTTON, wnd->wm);
  xrdp_list_insert_item(help->child_list, 0, (long)but);
  but->parent = help;
  but->owner = help;
  but->left = 120;
  but->top = 260;
  but->id = 1;
  but->tab_stop = 1;
  set_string(&but->caption1, "OK");
  /* draw it */
  help->focused_control = but;
  help->default_button = but;
  help->esc_button = but;
  xrdp_bitmap_invalidate(help, 0);
  xrdp_wm_set_focused(wnd->wm, help);
  return 0;
}

/*****************************************************************************/
int xrdp_wm_cancel_clicked(struct xrdp_bitmap* wnd)
{
  if (wnd != 0)
  {
    if (wnd->wm != 0)
    {
      if (wnd->wm->pro_layer != 0)
      {
        wnd->wm->pro_layer->term = 1;
      }
    }
  }
  return 0;
}

/*****************************************************************************/
int xrdp_wm_ok_clicked(struct xrdp_bitmap* wnd)
{
  struct xrdp_bitmap* combo;
  struct xrdp_bitmap* label;
  struct xrdp_bitmap* edit;
  struct xrdp_wm* wm;
  struct xrdp_list* names;
  struct xrdp_list* values;
  struct xrdp_mod_data* mod_data;
  int i;

  wm = wnd->wm;
  combo = xrdp_bitmap_get_child_by_id(wnd, 6);
  if (combo != 0)
  {
    mod_data = (struct xrdp_mod_data*)
             xrdp_list_get_item(combo->data_list, combo->item_index);
    if (mod_data != 0)
    {
      /* get the user typed values */
      i = 100;
      label = xrdp_bitmap_get_child_by_id(wnd, i);
      edit = xrdp_bitmap_get_child_by_id(wnd, i + 1);
      while (label != 0 && edit != 0)
      {
        set_mod_data_item(mod_data, label->caption1, edit->caption1);
        i += 2;
        label = xrdp_bitmap_get_child_by_id(wnd, i);
        edit = xrdp_bitmap_get_child_by_id(wnd, i + 1);
      }
      if (xrdp_wm_setup_mod(wm, mod_data) == 0)
      {
        /* gota copy these cause dialog gets freed */
        names = xrdp_list_create();
        names->auto_free = 1;
        for (i = 0; i < mod_data->names->count; i++)
        {
          xrdp_list_add_item(names,
            (long)g_strdup((char*)xrdp_list_get_item(mod_data->names, i)));
        }
        values = xrdp_list_create();
        values->auto_free = 1;
        for (i = 0; i < mod_data->values->count; i++)
        {
          xrdp_list_add_item(values,
            (long)g_strdup((char*)xrdp_list_get_item(mod_data->values, i)));
        }
        xrdp_wm_delete_all_childs(wm);
        if (!wm->pro_layer->term)
        {
          if (wm->mod->mod_start(wm->mod, wm->screen->width,
                                 wm->screen->height, wm->screen->bpp) != 0)
          {
            wm->pro_layer->term = 1; /* kill session */
          }
        }
        if (!wm->pro_layer->term)
        {
          for (i = 0; i < names->count; i++)
          {
            wm->mod->mod_set_param(wm->mod,
                         (char*)xrdp_list_get_item(names, i),
                         (char*)xrdp_list_get_item(values, i));
          }
          if (wm->mod->mod_connect(wm->mod) != 0)
          {
            /* totaly free mod */
            wm->mod_exit(wm->mod);
            g_free_library(wm->mod_handle);
            wm->mod = 0;
            wm->mod_handle = 0;
            wm->mod_init = 0;
            wm->mod_exit = 0;
          }
          else /* close connection log window if connection is ok */
          {
            if (wm->log_wnd != 0)
            {
              xrdp_bitmap_delete(wm->log_wnd);
            }
          }
        }
        if (!wm->pro_layer->term)
        {
          if (wm->mod != 0)
          {
            if (wm->mod->sck != 0)
            {
              wm->pro_layer->app_sck = wm->mod->sck;
            }
          }
        }
        xrdp_list_delete(names);
        xrdp_list_delete(values);
      }
    }
  }
  return 0;
}

/******************************************************************************/
int xrdp_wm_show_edits(struct xrdp_wm* self, struct xrdp_bitmap* combo)
{
  int count;
  int index;
  int insert_index;
  char* name;
  char* value;
  struct xrdp_mod_data* mod;
  struct xrdp_bitmap* b;

  /* free labels and edits, cause we gota create them */
  /* creation or combo changed */
  for (index = 100; index < 200; index++)
  {
    b = xrdp_bitmap_get_child_by_id(combo->parent, index);
    xrdp_bitmap_delete(b);
  }

  insert_index = xrdp_list_index_of(self->login_window->child_list,
                                    (long)combo);
  insert_index++;
  mod = (struct xrdp_mod_data*)
           xrdp_list_get_item(combo->data_list, combo->item_index);
  if (mod != 0)
  {
    count = 0;
    for (index = 0; index < mod->names->count; index++)
    {
      value = (char*)xrdp_list_get_item(mod->values, index);
      if (g_strncmp("ask", value, 3) == 0)
      {
        /* label */
        b = xrdp_bitmap_create(60, 20, self->screen->bpp,
                               WND_TYPE_LABEL, self);
        xrdp_list_insert_item(self->login_window->child_list, insert_index,
                              (long)b);
        insert_index++;
        b->parent = self->login_window;
        b->owner = self->login_window;
        b->left = 155;
        b->top = 60 + 25 * count;
        b->id = 100 + 2 * count;
        name = (char*)xrdp_list_get_item(mod->names, index);
        set_string(&b->caption1, name);
        /* edit */
        b = xrdp_bitmap_create(140, 20, self->screen->bpp,
                               WND_TYPE_EDIT, self);
        xrdp_list_insert_item(self->login_window->child_list, insert_index,
                              (long)b);
        insert_index++;
        b->parent = self->login_window;
        b->owner = self->login_window;
        b->left = 220;
        b->top = 60 + 25 * count;
        b->id = 100 + 2 * count + 1;
        b->pointer = 1;
        b->tab_stop = 1;
        b->caption1 = (char*)g_malloc(256, 1);
        g_strcpy(b->caption1, value + 3);
        b->edit_pos = g_strlen(b->caption1);
        if (self->login_window->focused_control == 0)
        {
          self->login_window->focused_control = b;
        }
        if (g_strcmp(name, "password") == 0)
        {
          b->password_char = '*';
        }
        count++;
      }
    }
  }
  return 0;
}

/*****************************************************************************/
/* all login screen events go here */
int xrdp_wm_login_notify(struct xrdp_bitmap* wnd,
                         struct xrdp_bitmap* sender,
                         int msg, long param1, long param2)
{
  struct xrdp_bitmap* b;
  struct xrdp_rect rect;
  int i;

  if (wnd->modal_dialog != 0 && msg != 100)
  {
    return 0;
  }
  if (msg == 1) /* click */
  {
    if (sender->id == 1) /* help button */
    {
      xrdp_wm_help_clicked(wnd);
    }
    else if (sender->id == 2) /* cancel button */
    {
      xrdp_wm_cancel_clicked(wnd);
    }
    else if (sender->id == 3) /* ok button */
    {
      xrdp_wm_ok_clicked(wnd);
    }
  }
  else if (msg == 2) /* mouse move */
  {
  }
  else if (msg == 100) /* modal result is done */
  {
    i = xrdp_list_index_of(wnd->wm->screen->child_list, (long)sender);
    if (i >= 0)
    {
      b = (struct xrdp_bitmap*)
              xrdp_list_get_item(wnd->wm->screen->child_list, i);
      xrdp_list_remove_item(sender->wm->screen->child_list, i);
      MAKERECT(rect, b->left, b->top, b->width, b->height);
      xrdp_bitmap_invalidate(wnd->wm->screen, &rect);
      xrdp_bitmap_delete(sender);
      wnd->modal_dialog = 0;
      xrdp_wm_set_focused(wnd->wm, wnd);
    }
  }
  else if (msg == CB_ITEMCHANGE) /* combo box change */
  {
    xrdp_wm_show_edits(wnd->wm, sender);
    xrdp_bitmap_invalidate(wnd, 0); /* invalidate the whole dialog for now */
  }
  return 0;
}

/******************************************************************************/
int xrdp_wm_login_fill_in_combo(struct xrdp_wm* self, struct xrdp_bitmap* b)
{
  struct xrdp_list* sections;
  struct xrdp_list* section_names;
  struct xrdp_list* section_values;
  int fd;
  int i;
  int j;
  char* p;
  char* q;
  char* r;
  struct xrdp_mod_data* mod_data;

  sections = xrdp_list_create();
  sections->auto_free = 1;
  section_names = xrdp_list_create();
  section_names->auto_free = 1;
  section_values = xrdp_list_create();
  section_values->auto_free = 1;
  fd = g_file_open("xrdp.ini");
  xrdp_file_read_sections(fd, sections);
  for (i = 0; i < sections->count; i++)
  {
    p = (char*)xrdp_list_get_item(sections, i);
    xrdp_file_read_section(fd, p, section_names, section_values);
    if (g_strcmp(p, "globals") == 0)
    {
    }
    else
    {
      mod_data = (struct xrdp_mod_data*)
                     g_malloc(sizeof(struct xrdp_mod_data), 1);
      mod_data->names = xrdp_list_create();
      mod_data->names->auto_free = 1;
      mod_data->values = xrdp_list_create();
      mod_data->values->auto_free = 1;
      g_strcpy(mod_data->name, p); /* set name in square bracket */
      for (j = 0; j < section_names->count; j++)
      {
        q = (char*)xrdp_list_get_item(section_names, j);
        r = (char*)xrdp_list_get_item(section_values, j);
        if (g_strcmp("name", q) == 0)
        {
          g_strcpy(mod_data->name, r);
        }
        else if (g_strcmp("lib", q) == 0)
        {
          g_strcpy(mod_data->lib, r);
        }
        else
        {
          xrdp_list_add_item(mod_data->names, (long)g_strdup(q));
          xrdp_list_add_item(mod_data->values, (long)g_strdup(r));
        }
      }
      xrdp_list_add_item(b->string_list, (long)g_strdup(mod_data->name));
      xrdp_list_add_item(b->data_list, (long)mod_data);
    }
  }
  g_file_close(fd);
  xrdp_list_delete(sections);
  xrdp_list_delete(section_names);
  xrdp_list_delete(section_values);
  return 0;
}

/******************************************************************************/
int xrdp_login_wnd_create(struct xrdp_wm* self)
{
  struct xrdp_bitmap* but;
  struct xrdp_bitmap* combo;

  /* draw login window */
  self->login_window = xrdp_bitmap_create(400, 200, self->screen->bpp,
                                          WND_TYPE_WND, self);
  xrdp_list_add_item(self->screen->child_list, (long)self->login_window);
  self->login_window->parent = self->screen;
  self->login_window->owner = self->screen;
  self->login_window->bg_color = self->grey;
  self->login_window->left = self->screen->width / 2 -
                             self->login_window->width / 2;
  self->login_window->top = self->screen->height / 2 -
                            self->login_window->height / 2;
  self->login_window->notify = xrdp_wm_login_notify;
  set_string(&self->login_window->caption1, "Login to xrdp");

  /* image */
  but = xrdp_bitmap_create(4, 4, self->screen->bpp, WND_TYPE_IMAGE, self);
  xrdp_bitmap_load(but, "xrdp256.bmp", self->palette);
  but->parent = self->screen;
  but->owner = self->screen;
  but->left = self->screen->width - but->width;
  but->top = self->screen->height - but->height;
  xrdp_list_add_item(self->screen->child_list, (long)but);

  /* image */
  but = xrdp_bitmap_create(4, 4, self->screen->bpp, WND_TYPE_IMAGE, self);
  xrdp_bitmap_load(but, "ad256.bmp", self->palette);
  but->parent = self->login_window;
  but->owner = self->login_window;
  but->left = 10;
  but->top = 30;
  xrdp_list_add_item(self->login_window->child_list, (long)but);

  /* label */
  but = xrdp_bitmap_create(60, 20, self->screen->bpp, WND_TYPE_LABEL, self);
  xrdp_list_add_item(self->login_window->child_list, (long)but);
  but->parent = self->login_window;
  but->owner = self->login_window;
  but->left = 155;
  but->top = 35;
  set_string(&but->caption1, "Module");

  /* combo */
  combo = xrdp_bitmap_create(140, 20, self->screen->bpp, WND_TYPE_COMBO, self);
  xrdp_list_add_item(self->login_window->child_list, (long)combo);
  combo->parent = self->login_window;
  combo->owner = self->login_window;
  combo->left = 220;
  combo->top = 35;
  combo->id = 6;
  combo->tab_stop = 1;
  xrdp_wm_login_fill_in_combo(self, combo);

  /* button */
  but = xrdp_bitmap_create(60, 25, self->screen->bpp, WND_TYPE_BUTTON, self);
  xrdp_list_add_item(self->login_window->child_list, (long)but);
  but->parent = self->login_window;
  but->owner = self->login_window;
  but->left = 180;
  but->top = 160;
  but->id = 3;
  set_string(&but->caption1, "OK");
  but->tab_stop = 1;
  self->login_window->default_button = but;

  /* button */
  but = xrdp_bitmap_create(60, 25, self->screen->bpp, WND_TYPE_BUTTON, self);
  xrdp_list_add_item(self->login_window->child_list, (long)but);
  but->parent = self->login_window;
  but->owner = self->login_window;
  but->left = 250;
  but->top = 160;
  but->id = 2;
  set_string(&but->caption1, "Cancel");
  but->tab_stop = 1;
  self->login_window->esc_button = but;

  /* button */
  but = xrdp_bitmap_create(60, 25, self->screen->bpp, WND_TYPE_BUTTON, self);
  xrdp_list_add_item(self->login_window->child_list, (long)but);
  but->parent = self->login_window;
  but->owner = self->login_window;
  but->left = 320;
  but->top = 160;
  but->id = 1;
  set_string(&but->caption1, "Help");
  but->tab_stop = 1;

  /* labels and edits */
  xrdp_wm_show_edits(self, combo);

  return 0;
}
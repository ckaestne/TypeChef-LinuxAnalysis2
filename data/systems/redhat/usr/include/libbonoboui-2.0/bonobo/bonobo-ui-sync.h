/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/*
 * bonobo-ui-sync.h: An abstract base for Bonobo XML / widget sync sync'ing.
 *
 * Author:
 *	Michael Meeks (michael@helixcode.com)
 *
 * Copyright 2000 Helix Code, Inc.
 */

#ifndef _BONOBO_UI_SYNC_H_
#define _BONOBO_UI_SYNC_H_

/* Internal API */
#ifdef BONOBO_UI_INTERNAL

#include <stdio.h>
#include <glib.h>
#include <gtk/gtk.h>
#include <bonobo/bonobo-ui-node.h>

typedef struct _BonoboUISync BonoboUISync;

#include <bonobo/bonobo-ui-engine.h>

G_BEGIN_DECLS

#define BONOBO_TYPE_UI_SYNC            (bonobo_ui_sync_get_type ())
#define BONOBO_UI_SYNC(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), BONOBO_TYPE_UI_SYNC, BonoboUISync))
#define BONOBO_UI_SYNC_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass), BONOBO_TYPE_UI_SYNC, BonoboUISyncClass))
#define BONOBO_IS_UI_SYNC(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), BONOBO_TYPE_UI_SYNC))
#define BONOBO_IS_UI_SYNC_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), BONOBO_TYPE_UI_SYNC))

typedef void (*BonoboUISyncStateFn)         (BonoboUISync     *sync,
					     BonoboUINode     *node,
					     BonoboUINode     *cmd_node,
					     GtkWidget        *widget,
					     GtkWidget        *parent);
	
typedef GtkWidget *(*BonoboUISyncBuildFn)   (BonoboUISync     *sync,
					     BonoboUINode     *node,
					     BonoboUINode     *cmd_node,
					     int              *pos,
					     GtkWidget        *parent);

typedef struct _BonoboUISyncPrivate BonoboUISyncPrivate;

struct _BonoboUISync {
	GObject parent;

	BonoboUIEngine *engine;
	gboolean        is_recursive;
	gboolean        has_widgets;

	BonoboUISyncPrivate *priv;
};

typedef struct {
	GObjectClass parent_class;

	BonoboUISyncStateFn sync_state;
	BonoboUISyncStateFn sync_state_placeholder;
	BonoboUISyncBuildFn build;
	BonoboUISyncBuildFn build_placeholder;

	void          (*update_root)     (BonoboUISync     *sync,
					  BonoboUINode     *root);

	void          (*remove_root)     (BonoboUISync     *sync,
					  BonoboUINode     *root);

	GList        *(*get_widgets)     (BonoboUISync     *sync,
					  BonoboUINode     *node);

	void          (*state_update)    (BonoboUISync     *sync,
					  GtkWidget        *widget,
					  const char       *new_state);
	
	gboolean      (*ignore_widget)   (BonoboUISync     *sync,
					  GtkWidget        *widget);
	
	gboolean      (*can_handle)      (BonoboUISync     *sync,
					  BonoboUINode     *node);
	
        void          (*stamp_root)      (BonoboUISync     *sync);

	GtkWidget    *(*get_attached)    (BonoboUISync     *sync,
					  GtkWidget        *widget,
					  BonoboUINode     *node);

	GtkWidget    *(*wrap_widget)     (BonoboUISync     *sync,
					  GtkWidget        *custom_widget);
} BonoboUISyncClass;

GType      bonobo_ui_sync_get_type           (void) G_GNUC_CONST;
BonoboUISync *bonobo_ui_sync_construct       (BonoboUISync     *sync,
					      BonoboUIEngine   *engine,
					      gboolean          is_recursive,
					      gboolean          has_widgets);

gboolean   bonobo_ui_sync_is_recursive       (BonoboUISync     *sync);
gboolean   bonobo_ui_sync_has_widgets        (BonoboUISync     *sync);

void       bonobo_ui_sync_remove_root        (BonoboUISync     *sync,
					      BonoboUINode     *root);
void       bonobo_ui_sync_update_root        (BonoboUISync     *sync,
					      BonoboUINode     *root);

void       bonobo_ui_sync_state              (BonoboUISync     *sync,
					      BonoboUINode     *node,
					      BonoboUINode     *cmd_node,
					      GtkWidget        *widget,
					      GtkWidget        *parent);
void       bonobo_ui_sync_state_placeholder  (BonoboUISync     *sync,
					      BonoboUINode     *node,
					      BonoboUINode     *cmd_node,
					      GtkWidget        *widget,
					      GtkWidget        *parent);

GtkWidget *bonobo_ui_sync_build              (BonoboUISync     *sync,
					      BonoboUINode     *node,
					      BonoboUINode     *cmd_node,
					      int              *pos,
					      GtkWidget        *parent);
GtkWidget *bonobo_ui_sync_build_placeholder  (BonoboUISync     *sync,
					      BonoboUINode     *node,
					      BonoboUINode     *cmd_node,
					      int              *pos,
					      GtkWidget        *parent);

gboolean   bonobo_ui_sync_ignore_widget      (BonoboUISync     *sync,
					      GtkWidget        *widget);

GList     *bonobo_ui_sync_get_widgets        (BonoboUISync     *sync,
					      BonoboUINode     *node);

void       bonobo_ui_sync_stamp_root         (BonoboUISync     *sync);

gboolean   bonobo_ui_sync_can_handle         (BonoboUISync     *sync,
					      BonoboUINode     *node);

GtkWidget *bonobo_ui_sync_get_attached       (BonoboUISync     *sync,
					      GtkWidget        *widget,
					      BonoboUINode     *node);

void       bonobo_ui_sync_state_update       (BonoboUISync     *sync,
					      GtkWidget        *widget,
					      const char       *new_state);

gboolean   bonobo_ui_sync_do_show_hide       (BonoboUISync     *sync,
					      BonoboUINode     *node,
					      BonoboUINode     *cmd_node,
					      GtkWidget        *widget);

GtkWidget *bonobo_ui_sync_wrap_widget        (BonoboUISync     *sync,
					      GtkWidget        *custom_widget);

/*
 *  These are to allow you to remove certain types of Sync
 * from a bonobo-window to allow full sub-classing of that.
 * Do not use to instantiate syncs manualy or to sub-class.
 */
GType bonobo_ui_sync_keys_get_type    (void);
GType bonobo_ui_sync_menu_get_type    (void);
GType bonobo_ui_sync_status_get_type  (void);
GType bonobo_ui_sync_toolbar_get_type (void);

G_END_DECLS

#endif /* BONOBO_UI_INTERNAL */

#endif /* _BONOBO_UI_SYNC_H_ */

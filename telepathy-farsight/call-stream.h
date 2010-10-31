/*
 * call-stream.h - Source for TfCallStream
 * Copyright (C) 2010 Collabora Ltd.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef __TF_CALL_STREAM_H__
#define __TF_CALL_STREAM_H__

#include <glib-object.h>

#include <gst/gst.h>
#include <telepathy-glib/channel.h>

#include "call-channel.h"
#include "call-content.h"
#include "extensions/extensions.h"

G_BEGIN_DECLS

#define TF_TYPE_STREAM tf_call_stream_get_type()

#define TF_CALL_STREAM(obj) \
  (G_TYPE_CHECK_INSTANCE_CAST ((obj), \
  TF_TYPE_STREAM, TfCallStream))

#define TF_CALL_STREAM_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_CAST ((klass), \
  TF_TYPE_STREAM, TfCallStreamClass))

#define TF_IS_STREAM(obj) \
  (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TF_TYPE_STREAM))

#define TF_IS_STREAM_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_TYPE ((klass), TF_TYPE_STREAM))

#define TF_CALL_STREAM_GET_CLASS(obj) \
  (G_TYPE_INSTANCE_GET_CLASS ((obj), \
  TF_TYPE_STREAM, TfCallStreamClass))

typedef struct _TfCallStreamPrivate TfCallStreamPrivate;

/**
 * TfCallStream:
 *
 * All members of the object are private
 */

typedef struct _TfCallStream TfCallStream;

/**
 * TfCallStreamClass:
 * @parent_class: the parent #GObjecClass
 *
 * There are no overridable functions
 */

typedef struct _TfCallStreamClass TfCallStreamClass;


struct _TfCallStream {
  GObject parent;

  TfCallContent *call_content;

  TfFutureCallStream *proxy;
};

struct _TfCallStreamClass{
  GObjectClass parent_class;
};


GType tf_call_stream_get_type (void);

TfCallStream *tf_call_stream_new (
    TfCallChannel *channel,
    TfCallContent *content,
    const gchar *object_path,
    GError **error);

G_END_DECLS

#endif /* __TF_CALL_STREAM_H__ */
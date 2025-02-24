/*
 * Copyright (C) 2025 Canonical Ltd.
 *
 * This library is free software; you can redistribute it and/or modify it under
 * the terms of the GNU Lesser General Public License as published by the Free
 * Software Foundation; either version 2 or version 3 of the License.
 * See http://www.gnu.org/copyleft/lgpl.html the full text of the license.
 */

#include "Snapd/wrapped-object.h"
#include <snapd-glib/snapd-glib.h>

QSnapdWrappedObject::QSnapdWrappedObject(void *object,
                                         void (*unref_func)(void *),
                                         QObject *parent)
    : QObject(parent), wrapped_object(object), unref_func(unref_func) {}
QSnapdWrappedObject::~QSnapdWrappedObject() { unref_func(wrapped_object); }

void *QSnapdWrappedObject::wrappedObject() { return wrapped_object; }

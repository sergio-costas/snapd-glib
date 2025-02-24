/*
 * Copyright (C) 2016 Canonical Ltd.
 *
 * This library is free software; you can redistribute it and/or modify it under
 * the terms of the GNU Lesser General Public License as published by the Free
 * Software Foundation; either version 2 or version 3 of the License.
 * See http://www.gnu.org/copyleft/lgpl.html the full text of the license.
 */

#ifndef SNAPD_WRAPPED_OBJECT_H
#define SNAPD_WRAPPED_OBJECT_H

#include <QtCore/QObject>

#if defined(LIBSNAPDQT)
#define LIBSNAPDQT_EXPORT __attribute__((visibility("default")))
#else
#define LIBSNAPDQT_EXPORT Q_DECL_IMPORT
#endif

class LIBSNAPDQT_EXPORT QSnapdWrappedObject : public QObject {
  Q_OBJECT

public:
  explicit QSnapdWrappedObject(void *object, void (*unref_func)(void *),
                               QObject *parent = NULL);
  ~QSnapdWrappedObject();

  void *wrappedObject();

protected:
  void *wrapped_object;

private:
  void (*unref_func)(void *);
};

#endif

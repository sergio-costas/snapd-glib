/*
 * Copyright (C) 2017 Canonical Ltd.
 *
 * This library is free software; you can redistribute it and/or modify it under
 * the terms of the GNU Lesser General Public License as published by the Free
 * Software Foundation; either version 2 or version 3 of the License.
 * See http://www.gnu.org/copyleft/lgpl.html the full text of the license.
 */

#pragma once

#include <libsoup/soup.h>
#include <json-glib/json-glib.h>

#include "snapd-alias.h"
#include "snapd-app.h"
#include "snapd-change.h"
#include "snapd-connection.h"
#include "snapd-interface.h"
#include "snapd-maintenance.h"
#include "snapd-notice.h"
#include "snapd-plug.h"
#include "snapd-plug-ref.h"
#include "snapd-slot.h"
#include "snapd-slot-ref.h"
#include "snapd-snap.h"
#include "snapd-system-information.h"
#include "snapd-user-information.h"

G_BEGIN_DECLS

void                  _snapd_json_set_body               (SoupMessage        *message,
                                                          JsonBuilder        *builder,
                                                          GBytes            **body);

gboolean              _snapd_json_get_bool               (JsonObject         *object,
                                                          const gchar        *name,
                                                          gboolean            default_value);

gint64                _snapd_json_get_int                (JsonObject         *object,
                                                          const gchar        *name,
                                                          gint64              default_value);

const gchar          *_snapd_json_get_string             (JsonObject         *object,
                                                          const gchar        *name,
                                                          const gchar        *default_value);

JsonArray            *_snapd_json_get_array              (JsonObject         *object,
                                                          const gchar        *name);

JsonObject           *_snapd_json_get_object             (JsonObject         *object,
                                                          const gchar        *name);

GDateTime            *_snapd_json_get_date_time          (JsonObject         *object,
                                                          const gchar        *name,
                                                          int                *nanoseconds);

JsonObject           *_snapd_json_parse_response         (const gchar        *content_type,
                                                          GBytes             *body,
                                                          SnapdMaintenance **maintenance,
                                                          JsonNode          **error_value,
                                                          GError            **error);

JsonNode             *_snapd_json_get_sync_result        (JsonObject         *response,
                                                          GError            **error);

JsonObject           *_snapd_json_get_sync_result_o      (JsonObject         *response,
                                                          GError            **error);

JsonArray            *_snapd_json_get_sync_result_a      (JsonObject         *response,
                                                          GError            **error);

gchar                *_snapd_json_get_async_result       (JsonObject         *response,
                                                          GError            **error);

GPtrArray            *_snapd_json_parse_notices          (JsonNode            *node,
                                                          GError             **error);

SnapdChange          *_snapd_json_parse_change           (JsonNode            *node,
                                                          GError            **error);

SnapdSystemInformation *_snapd_json_parse_system_information (JsonNode       *node,
                                                              GError        **error);

SnapdSnap            *_snapd_json_parse_snap             (JsonNode           *node,
                                                          GError            **error);

SnapdApp             *_snapd_json_parse_app              (JsonNode           *node,
                                                          const gchar        *snap_name,
                                                          GError            **error);

SnapdAlias           *_snapd_json_parse_alias            (JsonNode           *node,
                                                          const gchar        *snap_name,
                                                          const gchar        *name,
                                                          GError            **error);

SnapdUserInformation *_snapd_json_parse_user_information (JsonNode           *node,
                                                          GError            **error);

GHashTable           *_snapd_json_parse_object           (JsonObject         *node,
                                                          GError            **error);

GHashTable           *_snapd_json_parse_attributes       (JsonNode           *node,
                                                          GError            **error);

SnapdSlot            *_snapd_json_parse_slot             (JsonNode           *node,
                                                          GError            **error);

SnapdPlug            *_snapd_json_parse_plug             (JsonNode           *node,
                                                          GError            **error);

SnapdSlotRef         *_snapd_json_parse_slot_ref         (JsonNode           *node,
                                                          GError            **error);

SnapdPlugRef         *_snapd_json_parse_plug_ref         (JsonNode           *node,
                                                          GError            **error);

SnapdConnection      *_snapd_json_parse_connection       (JsonNode           *node,
                                                          GError            **error);

SnapdInterface       *_snapd_json_parse_interface        (JsonNode           *node,
                                                          GError            **error);

G_END_DECLS

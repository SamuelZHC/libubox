/*
 * ulog - simple logging functions
 *
 * Copyright (C) 2015 Jo-Philipp Wich <jow@openwrt.org>
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 *
 * Copyright 2016 yubo. All rights reserved.
 * Use of this source code is governed by a BSD-style
 * license that can be found in the LICENSE file.
 * Yu Bo <yubo@xiaomi.com>
 */

#ifndef __LIBUBOX_ULOG_H__
#define __LIBUBOX_ULOG_H__

#include <syslog.h>

enum {
	ULOG_KMSG   = (1 << 0),
	ULOG_SYSLOG = (1 << 1),
	ULOG_STDIO  = (1 << 2)
};

void ulog_open(int channels, int facility, const char *ident);
void ulog_close(void);

void ulog_threshold(int threshold);

void ulog(int priority, const char *fmt, ...);

#define ULOG_INFO(fmt, ...) ulog(LOG_INFO, fmt, ## __VA_ARGS__)
#define ULOG_NOTE(fmt, ...) ulog(LOG_NOTICE, fmt, ## __VA_ARGS__)
#define ULOG_WARN(fmt, ...) ulog(LOG_WARNING, fmt, ## __VA_ARGS__)
#define ULOG_ERR(fmt, ...) ulog(LOG_ERR, fmt, ## __VA_ARGS__)

#ifdef _DEBUG_
#define dlog(fmt, ...) ulog(LOG_DEBUG, fmt, ## __VA_ARGS__)
#else
#define dlog(fmt, ...) 
#endif

#define ilog(fmt, ...) ulog(LOG_INFO, fmt, ## __VA_ARGS__)
#define nlog(fmt, ...) ulog(LOG_NOTICE, fmt, ## __VA_ARGS__)
#define wlog(fmt, ...) ulog(LOG_WARNING, fmt, ## __VA_ARGS__)
#define elog(fmt, ...) ulog(LOG_ERR, fmt, ## __VA_ARGS__)

#endif

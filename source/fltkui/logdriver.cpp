/*
 * Nestopia UE
 *
 * Copyright (C) 2012-2024 R. Danbrook
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
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 *
 */

#include "videomanager.h"

#include "logdriver.h"

void LogDriver::jg_log(int level, const char *fmt, ...) {
    va_list va;
    char buffer[512];
    static const char *lcol[4] = {
        "\033[0;35m", "\033[0;36m", "\033[7;33m", "\033[1;7;31m"
    };

    va_start(va, fmt);
    vsnprintf(buffer, sizeof(buffer), fmt, va);
    va_end(va);

    FILE *fout = level == 1 ? stdout : stderr;

    if (level == JG_LOG_SCR) {
        VideoManager::text_print(buffer, 8, 212, 2, true);
        return;
    }

    fprintf(fout, "%s%s\033[0m", lcol[level], buffer);
    fflush(fout);

    if (level == JG_LOG_ERR) {
        VideoManager::text_print(buffer, 8, 212, 2, true);
    }
}

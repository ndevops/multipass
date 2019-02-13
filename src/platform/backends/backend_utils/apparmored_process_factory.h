/*
 * Copyright (C) 2019 Canonical, Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 3.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef MULTIPASS_APPARMOR_PROCESS_FACTORY_H
#define MULTIPASS_APPARMOR_PROCESS_FACTORY_H

#include "process_factory.h"
#include "process_spec.h"
#include "apparmor.h"

namespace multipass
{

class AppArmoredProcessFactory : public ProcessFactory
{
public:
    AppArmoredProcessFactory();
    virtual ~AppArmoredProcessFactory() = default;

    std::unique_ptr<Process> create_process(std::unique_ptr<ProcessSpec> &&process_spec) const override;

private:
    const AppArmor apparmor;
};

} // namespace multipass

#endif // MULTIPASS_APPARMOR_PROCESS_FACTORY_H
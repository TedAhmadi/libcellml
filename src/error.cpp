/*
Copyright 2015 University of Auckland

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/
#include "libcellml/error.h"

#include <string>

#include "libcellml/types.h"

namespace libcellml {

/**
 * @brief The Error::ErrorImpl struct.
 *
 * The private implementation for the Error class.
 */
struct Error::ErrorImpl
{
    std::string mDescription; /**< The string description for why this entity error raised. */
    Error::Kind mKind = Error::Kind::UNDEFINED; /**< The Error::Kind enum value for this error. */
    ComponentPtr mComponent; /**< Pointer to the component that the error occurred in. */
    ImportPtr mImport; /**< Pointer to the import that the error occurred in. */
    ModelPtr mModel; /**< Pointer to the model that the error occurred in. */
    UnitsPtr mUnits; /**< Pointer to the units that the error occurred in. */
    VariablePtr mVariable; /**< Pointer to the variable that the error occurred in. */
};

Error::Error()
    : mPimpl(new ErrorImpl())
{
}

Error::~Error()
{
    delete mPimpl;
}

Error::Error(const Error& rhs)
    : mPimpl(new ErrorImpl())
{
    mPimpl->mDescription = rhs.mPimpl->mDescription;
    mPimpl->mKind = rhs.mPimpl->mKind;
    mPimpl->mComponent = rhs.mPimpl->mComponent;
    mPimpl->mImport = rhs.mPimpl->mImport;
    mPimpl->mModel = rhs.mPimpl->mModel;
    mPimpl->mUnits = rhs.mPimpl->mUnits;
    mPimpl->mVariable = rhs.mPimpl->mVariable;
}

Error::Error(Error &&rhs)
    : mPimpl(rhs.mPimpl)
{
    rhs.mPimpl = nullptr;
}

Error& Error::operator=(Error rhs)
{
    rhs.swap(*this);
    return *this;
}

void Error::swap(Error &rhs)
{
    std::swap(this->mPimpl, rhs.mPimpl);
}

void Error::setDescription(const std::string &description)
{
    mPimpl->mDescription = description;
}

std::string Error::getDescription() const
{
    return mPimpl->mDescription;
}

void Error::setKind(Error::Kind kind)
{
    mPimpl->mKind = kind;
}

Error::Kind Error::getKind() const
{
    return mPimpl->mKind;
}

bool Error::isKind(const Error::Kind &kind)
{
    bool response = false;
    if (mPimpl->mKind == kind) {
        response = true;
    }
    return response;
}

void Error::setComponent(const ComponentPtr &component)
{
    mPimpl->mComponent = component;
}

ComponentPtr Error::getComponent()
{
    return mPimpl->mComponent;
}

const ComponentPtr& Error::getComponent() const
{
    return mPimpl->mComponent;
}

void Error::setImport(const ImportPtr &import)
{
    mPimpl->mImport = import;
}

ImportPtr Error::getImport()
{
    return mPimpl->mImport;
}

const ImportPtr& Error::getImport() const
{
    return mPimpl->mImport;
}

void Error::setModel(const ModelPtr &model)
{
    mPimpl->mModel = model;
}

ModelPtr Error::getModel()
{
    return mPimpl->mModel;
}

const ModelPtr& Error::getModel() const
{
    return mPimpl->mModel;
}

void Error::setUnits(const UnitsPtr &units)
{
    mPimpl->mUnits = units;
}

UnitsPtr Error::getUnits()
{
    return mPimpl->mUnits;
}

const UnitsPtr& Error::getUnits() const
{
    return mPimpl->mUnits;
}

void Error::setVariable(const VariablePtr &variable)
{
    mPimpl->mVariable = variable;
}

VariablePtr Error::getVariable()
{
    return mPimpl->mVariable;
}

const VariablePtr& Error::getVariable() const
{
    return mPimpl->mVariable;
}

}

/****************************************************************************
**
** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/
**
** This file is part of the QtXmlPatterns module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** GNU Lesser General Public License Usage
** This file may be used under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation and
** appearing in the file LICENSE.LGPL included in the packaging of this
** file. Please review the following information to ensure the GNU Lesser
** General Public License version 2.1 requirements will be met:
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights. These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU General
** Public License version 3.0 as published by the Free Software Foundation
** and appearing in the file LICENSE.GPL included in the packaging of this
** file. Please review the following information to ensure the GNU General
** Public License version 3.0 requirements will be met:
** http://www.gnu.org/copyleft/gpl.html.
**
** Other Usage
** Alternatively, this file may be used in accordance with the terms and
** conditions contained in a signed written agreement between you and Nokia.
**
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists purely as an
// implementation detail.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.

#ifndef Patternist_HexBinary_H
#define Patternist_HexBinary_H

#include "qbase64binary_p.h"

QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE

namespace QPatternist
{

    /**
     * @short Implements the value instance of the @c xs:hexBinary type.
     *
     * HexBinary inherits from Base64Binary for implementation reasons. The two
     * classes are similar, and inheritance therefore save code.
     *
     * @author Frans Englich <frans.englich@nokia.com>
     * @ingroup Patternist_xdm
     * @todo Documentation is missing
     */
    class HexBinary : public Base64Binary
    {
    public:
        friend class CommonValues;

        typedef AtomicValue::Ptr Ptr;

        virtual QString stringValue() const;
        virtual ItemType::Ptr type() const;

        /**
         * Creates a @c xs:hexBinary from the lexical representation @p value.
         */
        static AtomicValue::Ptr fromLexical(const NamePool::Ptr &np, const QString &value);

        /**
         * Creates an instance representing @p value.
         */
        static HexBinary::Ptr fromValue(const QByteArray &data);

    protected:
        HexBinary(const QByteArray &val);

    private:
        /**
         * @short Returns -1 on invalid input.
         */
        static inline qint8 fromHex(const QChar &c);
    };
}

QT_END_NAMESPACE

QT_END_HEADER

#endif

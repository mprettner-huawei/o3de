#pragma once

namespace AzToolsFramework
{

}

#include <QKeySequence>

class QKeyCombination
{
    Qt::Modifier m_modifier;
    Qt::Key m_key;

public:
    QKeyCombination(Qt::Modifier modifier, Qt::Key key)
        : m_modifier{ modifier }
        , m_key{ key }
    {
    }

    int toCombined() const
    {
        return static_cast<int>(m_modifier) | static_cast<int>(m_key);
    }

    // Emulate QKeySequence(QKeyCombination) constructor from qt6
    operator int() const
    {
        return toCombined();
    }
};

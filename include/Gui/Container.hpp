////////////////////////////////////////////////////////////
//
// This file is part of DRIMI::Gui.
// Copyright (C) 2013-2016 Acroute Anthony (ant110283@hotmail.fr)
//
// DRIMI::Gui is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 2 of the License, or
// (at your option) any later version.
//
// DRIMI::Gui is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with DRIMI::Gui.  If not, see <http://www.gnu.org/licenses/>.
//
// A part of the code in this file is inspired by the book
// "SFML Game Development".
//
////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
// Description for Doxygen
////////////////////////////////////////////////////////////
/**
 * \file Container.hpp
 * \brief Class for the container of the gui.
 * \author Anthony Acroute
 * \version 0.1
 * \date 2016
 *
 */

#ifndef CONTAINER_HPP__
#define CONTAINER_HPP__

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <DRIMI/Gui/Component.hpp>

#include <vector>

////////////////////////////////////////////////////////////
/// \brief Class to define a container of the gui which
/// has for function to contains components.
///
////////////////////////////////////////////////////////////
namespace drimi {
namespace Gui {

class Container : public Component {

  public :
    ////////////////////////////////////////////////////////////
    // Types
    ////////////////////////////////////////////////////////////
    typedef std::shared_ptr<Container>  Ptr;  ///< Unique pointer of container.

  private :
    ////////////////////////////////////////////////////////////
    // Member data
    ////////////////////////////////////////////////////////////
    std::vector<Component::Ptr> m_oChildren;
    GLint                       m_iSelectedChild;

  public :
    ////////////////////////////////////////////////////////////
    // Constructor(s)/Destructor
    ////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////
    /// \brief Default constructor.
    ///
    /// This constructor defines a container.
    ///
    ////////////////////////////////////////////////////////////
    Container ( void );

    ////////////////////////////////////////////////////////////
    /// \brief Destructor.
    ///
    /// Cleans up all the internal resources used by the container.
    ///
    ////////////////////////////////////////////////////////////
    ~Container ( void );

    ////////////////////////////////////////////////////////////
    // General methods
    ////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////
    /// \brief Store components of the gui.
    ///
    /// \param pComponent   The component to store in the container.
    ///
    ////////////////////////////////////////////////////////////
    void Pack ( Component::Ptr pComponent );

    ////////////////////////////////////////////////////////////
    /// \brief Check the events for the container.
    ///
    /// \param eEventType   The current event type.
    ///        sfKeyCode    The current keyboard key code.
    ///
    /// \return True to permit the events of the other components to be checked, false else.
    ///
    ////////////////////////////////////////////////////////////
    virtual GLboolean HandleEvent ( const drimi::Event::Type eEventType, const sf::Keyboard::Key sfKeyCode );

    ////////////////////////////////////////////////////////////
    /// \brief Transmit a unicode text to the container.
    ///
    /// \param cUnicode   The current text unicode.
    ///
    /// \return True to permit the text unicode transmission of the other components to be checked, false else.
    ///
    ////////////////////////////////////////////////////////////
    virtual GLboolean HandleTextUnicode ( const char cUnicode );

    ////////////////////////////////////////////////////////////
    /// \brief Update the composants of the container.
    ///
    ////////////////////////////////////////////////////////////
    virtual void Update ( void );

    ////////////////////////////////////////////////////////////
    /// \brief Draw all the composants of the container.
    ///
    /// \param sfTarget   The render target to draw.
    ///        sfStates   The current render states.
    ///
    ////////////////////////////////////////////////////////////
    virtual void draw ( sf::RenderTarget& target, sf::RenderStates states ) const;
    virtual void Draw ( sf::RenderTarget& sfTarget, sf::RenderStates sfStates = sf::RenderStates::Default );

  private :
    ////////////////////////////////////////////////////////////
    /// \brief Get if the container has a selection or not.
    ///
    /// \return True if the container has a selection, false else.
    ///
    ////////////////////////////////////////////////////////////
    GLboolean HasSelection ( void ) const;

    ////////////////////////////////////////////////////////////
    /// \brief Select the component.
    ///
    /// \param iIndex   The index of the component.
    ///
    ////////////////////////////////////////////////////////////
    virtual void Select ( std::size_t iIndex );

    ////////////////////////////////////////////////////////////
    /// \brief Select the next component.
    ///
    ////////////////////////////////////////////////////////////
    virtual void SelectNext ( void );

    ////////////////////////////////////////////////////////////
    /// \brief Select the previous component.
    ///
    ////////////////////////////////////////////////////////////
    virtual void SelectPrevious ( void );

  public :
    ////////////////////////////////////////////////////////////
    // Accessor methods
    ////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////
    /// \brief Get if the container is selectable or not.
    ///
    /// \return True to if the container is selectable, false else.
    ///
    ////////////////////////////////////////////////////////////
    virtual GLboolean IsSelectable ( void ) const;

    ////////////////////////////////////////////////////////////
    /// \brief Set position of the container.
    ///
    /// \param fX   The X value of the position.
    ///        fY   The Y value of the position.
    ///
    ////////////////////////////////////////////////////////////
    virtual void SetPosition ( GLfloat fX, GLfloat fY ) { setPosition (fX, fY); }

    ////////////////////////////////////////////////////////////
    /// \brief Set origin of the container.
    ///
    /// \param fX   The X value of the origin.
    ///        fY   The Y value of the origin.
    ///
    ////////////////////////////////////////////////////////////
    virtual void SetOrigin ( GLfloat fX, GLfloat fY ) { setOrigin (fX, fY); }
};

} // namespace Gui
} // namespace drimi

#endif // CONTAINER_HPP__

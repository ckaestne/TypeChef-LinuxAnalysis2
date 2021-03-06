/*
 * This file is part of the syndication library
 *
 * Copyright (C) 2005 Frank Osterfeld <osterfeld@kde.org>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You must have received a copy of the GNU Library General Public License
 * along with this library; see the file COPYING.LIB.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 *
 */
#ifndef SYNDICATION_DOCUMENTVISITOR_H
#define SYNDICATION_DOCUMENTVISITOR_H

#include "ksyndication_export.h"

namespace Syndication {

class SpecificDocument;

namespace Atom
{
    class EntryDocument;
    class FeedDocument;
}

namespace RDF
{
    class Document;
}

namespace RSS2
{
    class Document;
}

/**
 * Visitor interface, following the Visitor design pattern. Use this if you
 * want to process documents and the way how to handle the document depends
 * on it's concrete type (e.g. RSS2::Document, RDF::Document...).
 *
 * TODO: insert code example
 *
 * @author Frank Osterfeld
 */
class SYNDICATION_EXPORT DocumentVisitor //krazy:exclude=dpointer
{
    public:

        /**
         * destructor
         */
        virtual ~DocumentVisitor();

        /**
         * call this method to handle a document. Depending on the concrete type
         * of the document, a specialized visit method is called.
         *
         * @param document the document to process
         * @return whether this visitor handles the type of the document.
         */
        virtual bool visit(SpecificDocument* document);

        /**
         * reimplement this method to handle RSS2-like (RSS 0.9x, 2.0) documents.
         *
         * @param document the RSS2 document to visit
         * @return whether the visitor handled the document.
         * Reimplementations of this method must return @c true.
         */
        virtual bool visitRSS2Document(Syndication::RSS2::Document* document);

        /**
         * reimplement this method to handle RDF (i.e. RSS 1.0) documents.
         *
         * @param document the RDF document to visit
         * @return whether the visitor handled the document.
         * Reimplementations of this method must return @c true.
         */
        virtual bool visitRDFDocument(Syndication::RDF::Document* document);

        /**
         * reimplement this method to handle Atom feed documents (most Atom
         * feeds are of this type).
         *
         * @param document the atom feed document to visit
         * @return whether the visitor handled the document.
         * Reimplementations of this method must return @c true.
         */
        virtual bool visitAtomFeedDocument(Syndication::Atom::FeedDocument* document);

        /**
         * reimplement this method to handle Atom entry documents.
         *
         * @param document the atom entry document to visit
         * @return whether the visitor handled the document.
         * Reimplementations of this method must return @c true.
         */
        virtual bool visitAtomEntryDocument(Syndication::Atom::EntryDocument* document);
};

} // namespace Syndication

#endif // SYNDICATION_DOCUMENTVISITOR_H

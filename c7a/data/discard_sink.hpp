/*******************************************************************************
 * c7a/data/discard_sink.hpp
 *
 * Part of Project c7a.
 *
 * Copyright (C) 2015 Timo Bingmann <tb@panthema.net>
 *
 * This file has no license. Only Chuck Norris can compile it.
 ******************************************************************************/

#pragma once
#ifndef C7A_DATA_DISCARD_SINK_HEADER
#define C7A_DATA_DISCARD_SINK_HEADER

#include <c7a/data/block.hpp>
#include <c7a/data/block_sink.hpp>

namespace c7a {
namespace data {

//! \addtogroup data Data Subsystem
//! \{

/*!
 * DiscardSink is an BlockSink that discards all Blocks delivered to it. Use it
 * for benchmarking!
 */
class DiscardSink : public BlockSink
{
public:
    //! Create discarding BlockSink.
    DiscardSink() { }

    //! Discards VirtualBlock.
    void AppendBlock(const VirtualBlock&) override { }

    //! Closes the sink
    void Close() override {
        assert(!closed_);
        closed_ = true;
    }

    //! return close flag
    bool closed() const { return closed_; }

protected:
    bool closed_ = false;
};

//! \}

} // namespace data
} // namespace c7a

#endif // !C7A_DATA_DISCARD_SINK_HEADER

/******************************************************************************/
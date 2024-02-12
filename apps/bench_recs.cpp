/**
 *  Copyright 2015 Mike Reed
 */

#include "bench.h"
#include "../include/GCanvas.h"
#include "../include/GBitmap.h"
#include "../include/GColor.h"
#include "../include/GRandom.h"
#include "../include/GRect.h"
#include <string>

#include "bench_pa1.inc"
#include "bench_pa2.inc"
#include "bench_pa3.inc"

const GBenchmark::Factory gBenchFactories[] {
    []() -> GBenchmark* { return new ClearBench(); },
    []() -> GBenchmark* { return new RectsBench(false); },
    []() -> GBenchmark* { return new RectsBench(true);  },
    []() -> GBenchmark* {
        return new SingleRectBench({2,2}, GRect::LTRB(-1000, -1000, 1002, 1002), "rect_big");
    },
    []() -> GBenchmark* {
        return new SingleRectBench({1000,1000}, GRect::LTRB(500, 500, 502, 502), "rect_tiny");
    },

    // pa2
    []() -> GBenchmark* { return new PolyRectsBench(false); },
    []() -> GBenchmark* { return new PolyRectsBench(true);  },
    []() -> GBenchmark* { return new CirclesBench(false); },
    []() -> GBenchmark* { return new CirclesBench(true);  },
    []() -> GBenchmark* { return new ModesBench({1, 0.5, 0.25, 0.0}, "modes_0"); },
    []() -> GBenchmark* { return new ModesBench({1, 0.5, 0.25, 0.5}, "modes_x"); },
    []() -> GBenchmark* { return new ModesBench({1, 0.5, 0.25, 1.0}, "modes_1"); },

    // pa3
    []() -> GBenchmark* { return new BitmapBench("apps/spock.png", "bitmap_opaque"); },
    []() -> GBenchmark* { return new BitmapBench("apps/wheel.png", "bitmap_alpha"); },

    nullptr,
};

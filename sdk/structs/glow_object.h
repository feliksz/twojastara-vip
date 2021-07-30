#pragma once
#include <cstdint>
struct GlowObject {
	float m_color_r;
	float m_color_g;
	float m_color_b;
	float m_color_a;
	uint8_t __pad[ 16 ];
	bool m_render_occluded;
	bool m_render_unoccluded;
	bool m_full_bloom_render;
	uint8_t __pad2[ 4 ];
	int m_glow_style;
};
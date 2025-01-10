/*
 * Copyright (c) Contributors to the Open 3D Engine Project.
 * For complete copyright and license terms please see the LICENSE at the root of this distribution.
 *
 * SPDX-License-Identifier: Apache-2.0 OR MIT
 *
 */

#pragma once

#include <AzCore/Math/Vector2.h>
#include <AzCore/Math/Vector3.h>
#include <AzCore/Math/Vector4.h>

namespace AZ
{
    //! A color class with 4 components, RGBA.
    class AZCORE_API Color
    {
    public:

        AZ_TYPE_INFO(Color, "{7894072A-9050-4F0F-901B-34B1A0D29417}");

        //! AzCore Reflection.
        //! @param context reflection context
        static void Reflect(ReflectContext* context);

        //! Default constructor, components are uninitialized.
        Color() = default;
        Color(const Vector4& v)   { m_color = v; }

        explicit Color(const Vector2& source);

        explicit Color(const Vector3& source);

        //! Constructs vector with all components set to the same specified value.
        explicit Color(float rgba);

        Color(float r, float g, float b, float a);

        Color(u8 r, u8 g, u8 b);

        Color(u8 r, u8 g, u8 b, u8 a);

        //! Creates a vector with all components set to zero, more efficient than calling Color(0.0f).
        static Color CreateZero();

        //! Creates a vector with all components set to one.
        static Color CreateOne();

        //! Sets components from rgba.
        static Color CreateFromRgba(u8 r, u8 g, u8 b, u8 a);

        //! Sets components from an array of 4 floats, stored in xyzw order.
        static Color CreateFromFloat4(const float* values);

        //! Copies r,g,b components from a Vector3, sets w to 1.0.
        static Color CreateFromVector3(const Vector3& v);

        //! Copies r,g,b components from a Vector3, specify w separately.
        static Color CreateFromVector3AndFloat(const Vector3& v, float w);

        //! r,g,b,a to u32 => 0xAABBGGRR (COLREF format).
        static u32 CreateU32(u8 r, u8 g, u8 b, u8 a);

        //! Stores the vector to an array of 4 floats.
        //! The floats need only be 4 byte aligned, 16 byte alignment is not required.
        void StoreToFloat4(float* values) const;

        u8 GetR8() const;
        u8 GetG8() const;
        u8 GetB8() const;
        u8 GetA8() const;

        void SetR8(u8 r);
        void SetG8(u8 g);
        void SetB8(u8 b);
        void SetA8(u8 a);

        float GetR() const;
        float GetG() const;
        float GetB() const;
        float GetA() const;

        void SetR(float r);
        void SetG(float g);
        void SetB(float b);
        void SetA(float a);

        float GetElement(int32_t index) const;
        void SetElement(int32_t index, float v);

        Vector3 GetAsVector3() const;

        Vector4 GetAsVector4() const;

        //! Sets all components to the same specified value.
        void Set(float x);

        void Set(float r, float g, float b, float a);

        //! Sets components from an array of 4 floats, stored in rgba order.
        void Set(const float values[4]);

        //! Sets r,g,b components from a Vector3, sets a to 1.0.
        void Set(const Vector3& v);

        //! Sets r,g,b components from a Vector3, specify a separately.
        void Set(const Vector3& v, float a);

        //! Sets the RGB values of this Color based on a passed in hue, saturation, and value. Alpha is unchanged.
        void SetFromHSVRadians(float hueRadians, float saturation, float value);

        //! Checks the color is equal to another within a floating point tolerance.
        bool IsClose(const Color& v, float tolerance = Constants::Tolerance) const;

        bool IsZero(float tolerance = Constants::FloatEpsilon) const;

        //! Checks whether all components are finite.
        bool IsFinite() const;

        bool operator==(const Color& rhs) const;
        bool operator!=(const Color& rhs) const;

        explicit operator Vector3() const;
        explicit operator Vector4() const;

        Color& operator=(const Vector3& rhs);

        //! Color to u32 => 0xAABBGGRR.
        u32 ToU32() const;

        //! Color to u32 => 0xAABBGGRR, RGB convert from Linear to Gamma corrected values.
        u32 ToU32LinearToGamma() const;

        //! Color from u32 => 0xAABBGGRR.
        void FromU32(u32 c);

        //! Color from u32 => 0xAABBGGRR, RGB convert from Gamma corrected to Linear values.
        void FromU32GammaToLinear(u32 c);

        //! Convert SRGB gamma space to linear space
        static float ConvertSrgbGammaToLinear(float x);

        //! Convert SRGB linear space to gamma space
        static float ConvertSrgbLinearToGamma(float x);

        //! Convert color from linear to gamma corrected space.
        Color LinearToGamma() const;

        //! Convert color from gamma corrected to linear space.
        Color GammaToLinear() const;

        //! Comparison functions, not implemented as operators since that would probably be a little dangerous. These
        //! functions return true only if all components pass the comparison test.
        //! @{
        bool IsLessThan(const Color& rhs) const;
        bool IsLessEqualThan(const Color& rhs) const;
        bool IsGreaterThan(const Color& rhs) const;
        bool IsGreaterEqualThan(const Color& rhs) const;
        //! @}

        //! Linear interpolation between this color and a destination.
        //! @return (*this)*(1-t) + dest*t
        Color Lerp(const Color& dest, float t) const;

        //! Dot product of two colors, uses all 4 components.
        float Dot(const Color& rhs) const;

        //! Dot product of two colors, using only the r,g,b components.
        float Dot3(const Color& rhs) const;

        Color operator-() const;
        Color operator+(const Color& rhs) const;
        Color operator-(const Color& rhs) const;
        Color operator*(const Color& rhs) const;
        Color operator/(const Color& rhs) const;
        Color operator*(float multiplier) const;
        Color operator/(float divisor) const;

        Color& operator+=(const Color& rhs);
        Color& operator-=(const Color& rhs);
        Color& operator*=(const Color& rhs);
        Color& operator/=(const Color& rhs);
        Color& operator*=(float multiplier);
        Color& operator/=(float divisor);

    private:

        Vector4 m_color;

    };

    // Named colors, from CSS specification: https://www.w3.org/TR/2011/REC-SVG11-20110816/types.html#ColorKeywords
    namespace Colors
    {
        // clang-format off
        // Basic Colors (CSS 1 standard)
        const inline Color White                (255, 255, 255);
        const inline Color Silver               (192, 192, 192);
        const inline Color Gray                 (128, 128, 128);
        const inline Color Black                (  0,   0,   0);
        const inline Color Red                  (255,   0,   0);
        const inline Color Maroon               (128,   0,   0);
        const inline Color Lime                 (  0, 255,   0);
        const inline Color Green                (  0, 128,   0);
        const inline Color Blue                 (  0,   0, 255);
        const inline Color Navy                 (  0,   0, 128);
        const inline Color Yellow               (255, 255,   0);
        const inline Color Orange               (255, 165,   0);
        const inline Color Olive                (128, 128,   0);
        const inline Color Purple               (128,   0, 128);
        const inline Color Fuchsia              (255,   0, 255);
        const inline Color Teal                 (  0, 128, 128);
        const inline Color Aqua                 (  0, 255, 255);
        // CSS3 colors
        // Reds
        const inline Color IndianRed            (205,  92,  92);
        const inline Color LightCoral           (240, 128, 128);
        const inline Color Salmon               (250, 128, 114);
        const inline Color DarkSalmon           (233, 150, 122);
        const inline Color LightSalmon          (255, 160, 122);
        const inline Color Crimson              (220,  20,  60);
        const inline Color FireBrick            (178,  34,  34);
        const inline Color DarkRed              (139,   0,   0);
        // Pinks
        const inline Color Pink                 (255, 192, 203);
        const inline Color LightPink            (255, 182, 193);
        const inline Color HotPink              (255, 105, 180);
        const inline Color DeepPink             (255,  20, 147);
        const inline Color MediumVioletRed      (199,  21, 133);
        const inline Color PaleVioletRed        (219, 112, 147);
        // Oranges
        const inline Color Coral                (255, 127,  80);
        const inline Color Tomato               (255,  99,  71);
        const inline Color OrangeRed            (255,  69,   0);
        const inline Color DarkOrange           (255, 140,   0);
        // Yellows
        const inline Color Gold                 (255, 215,   0);
        const inline Color LightYellow          (255, 255, 224);
        const inline Color LemonChiffon         (255, 250, 205);
        const inline Color LightGoldenrodYellow (250, 250, 210);
        const inline Color PapayaWhip           (255, 239, 213);
        const inline Color Moccasin             (255, 228, 181);
        const inline Color PeachPuff            (255, 218, 185);
        const inline Color PaleGoldenrod        (238, 232, 170);
        const inline Color Khaki                (240, 230, 140);
        const inline Color DarkKhaki            (189, 183, 107);
        // Purples
        const inline Color Lavender             (230, 230, 250);
        const inline Color Thistle              (216, 191, 216);
        const inline Color Plum                 (221, 160, 221);
        const inline Color Violet               (238, 130, 238);
        const inline Color Orchid               (218, 112, 214);
        const inline Color Magenta              (255,   0, 255);
        const inline Color MediumOrchid         (186,  85, 211);
        const inline Color MediumPurple         (147, 112, 219);
        const inline Color BlueViolet           (138,  43, 226);
        const inline Color DarkViolet           (148,   0, 211);
        const inline Color DarkOrchid           (153,  50, 204);
        const inline Color DarkMagenta          (139,   0, 139);
        const inline Color RebeccaPurple        (102,  51, 153);
        const inline Color Indigo               ( 75,   0, 130);
        const inline Color MediumSlateBlue      (123, 104, 238);
        const inline Color SlateBlue            (106,  90, 205);
        const inline Color DarkSlateBlue        ( 72,  61, 139);
        // Greens
        const inline Color GreenYellow          (173, 255,  47);
        const inline Color Chartreuse           (127, 255,   0);
        const inline Color LawnGreen            (124, 252,   0);
        const inline Color LimeGreen            ( 50, 205,  50);
        const inline Color PaleGreen            (152, 251, 152);
        const inline Color LightGreen           (144, 238, 144);
        const inline Color MediumSpringGreen    (  0, 250, 154);
        const inline Color SpringGreen          (  0, 255, 127);
        const inline Color MediumSeaGreen       ( 60, 179, 113);
        const inline Color SeaGreen             ( 46, 139,  87);
        const inline Color ForestGreen          ( 34, 139,  34);
        const inline Color DarkGreen            (  0, 100,   0);
        const inline Color YellowGreen          (154, 205,  50);
        const inline Color OliveDrab            (107, 142,  35);
        const inline Color DarkOliveGreen       ( 85, 107,  47);
        const inline Color MediumAquamarine     (102, 205, 170);
        const inline Color DarkSeaGreen         (143, 188, 143);
        const inline Color LightSeaGreen        ( 32, 178, 170);
        const inline Color DarkCyan             (  0, 139, 139);
        // Blues
        const inline Color Cyan                 (  0, 255, 255);
        const inline Color LightCyan            (224, 255, 255);
        const inline Color PaleTurquoise        (175, 238, 238);
        const inline Color Aquamarine           (127, 255, 212);
        const inline Color Turquoise            ( 64, 224, 208);
        const inline Color MediumTurquoise      ( 72, 209, 204);
        const inline Color DarkTurquoise        (  0, 206, 209);
        const inline Color CadetBlue            ( 95, 158, 160);
        const inline Color SteelBlue            ( 70, 130, 180);
        const inline Color LightSteelBlue       (176, 196, 222);
        const inline Color PowderBlue           (176, 224, 230);
        const inline Color LightBlue            (173, 216, 230);
        const inline Color SkyBlue              (135, 206, 235);
        const inline Color LightSkyBlue         (135, 206, 250);
        const inline Color DeepSkyBlue          (  0, 191, 255);
        const inline Color DodgerBlue           ( 30, 144, 255);
        const inline Color CornflowerBlue       (100, 149, 237);
        const inline Color RoyalBlue            ( 65, 105, 225);
        const inline Color MediumBlue           (  0,   0, 205);
        const inline Color DarkBlue             (  0,   0, 139);
        const inline Color MidnightBlue         ( 25,  25, 112);
        // Browns
        const inline Color Cornsilk             (255, 248, 220);
        const inline Color BlanchedAlmond       (255, 235, 205);
        const inline Color Bisque               (255, 228, 196);
        const inline Color NavajoWhite          (255, 222, 173);
        const inline Color Wheat                (245, 222, 179);
        const inline Color BurlyWood            (222, 184, 135);
        const inline Color Tan                  (210, 180, 140);
        const inline Color RosyBrown            (188, 143, 143);
        const inline Color SandyBrown           (244, 164,  96);
        const inline Color Goldenrod            (218, 165,  32);
        const inline Color DarkGoldenrod        (184, 134,  11);
        const inline Color Peru                 (205, 133,  63);
        const inline Color Chocolate            (210, 105,  30);
        const inline Color SaddleBrown          (139,  69,  19);
        const inline Color Sienna               (160,  82,  45);
        const inline Color Brown                (165,  42,  42);
        // Whites
        const inline Color Snow                 (255, 250, 250);
        const inline Color Honeydew             (240, 255, 240);
        const inline Color MintCream            (245, 255, 250);
        const inline Color Azure                (240, 255, 255);
        const inline Color AliceBlue            (240, 248, 255);
        const inline Color GhostWhite           (248, 248, 255);
        const inline Color WhiteSmoke           (245, 245, 245);
        const inline Color Seashell             (255, 245, 238);
        const inline Color Beige                (245, 245, 220);
        const inline Color OldLace              (253, 245, 230);
        const inline Color FloralWhite          (255, 250, 240);
        const inline Color Ivory                (255, 255, 240);
        const inline Color AntiqueWhite         (250, 235, 215);
        const inline Color Linen                (250, 240, 230);
        const inline Color LavenderBlush        (255, 240, 245);
        const inline Color MistyRose            (255, 228, 225);
        // Grays
        const inline Color Gainsboro            (220, 220, 220);
        const inline Color LightGray            (211, 211, 211);
        const inline Color LightGrey            (211, 211, 211);
        const inline Color DarkGray             (169, 169, 169);
        const inline Color DarkGrey             (169, 169, 169);
        const inline Color Grey                 (128, 128, 128);
        const inline Color DimGray              (105, 105, 105);
        const inline Color DimGrey              (105, 105, 105);
        const inline Color LightSlateGray       (119, 136, 153);
        const inline Color LightSlateGrey       (119, 136, 153);
        const inline Color SlateGray            (112, 128, 144);
        const inline Color SlateGrey            (112, 128, 144);
        const inline Color DarkSlateGray        ( 47,  79,  79);
        const inline Color DarkSlateGrey        ( 47,  79,  79);
        // clang-format on
    }
}

#include <AzCore/Math/Color.inl>

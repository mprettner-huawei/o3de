/*
 * Copyright (c) Contributors to the Open 3D Engine Project.
 * For complete copyright and license terms please see the LICENSE at the root of this distribution.
 *
 * SPDX-License-Identifier: Apache-2.0 OR MIT
 *
 */

#pragma once

#include <AzCore/ApiConfiguration.h>
#include <AzCore/Math/Vector2.h>
#include <AzCore/Math/Vector3.h>
#include <AzCore/Math/Vector4.h>

namespace AZ
{
    //! A color class with 4 components, RGBA.
    class Color
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
        // Basic Colors (CSS 1 standard)
        AZCORE_API extern const Color White;                       // RGB: (255, 255, 255)
        AZCORE_API extern const Color Silver;                      // RGB: (192, 192, 192)
        AZCORE_API extern const Color Gray;                        // RGB: (128, 128, 128)
        AZCORE_API extern const Color Black;                       // RGB: (0, 0, 0)
        AZCORE_API extern const Color Red;                         // RGB: (255, 0, 0)
        AZCORE_API extern const Color Maroon;                      // RGB: (128, 0, 0)
        AZCORE_API extern const Color Lime;                        // RGB: (0, 255, 0)
        AZCORE_API extern const Color Green;                       // RGB: (0, 128, 0)
        AZCORE_API extern const Color Blue;                        // RGB: (0, 0, 255)
        AZCORE_API extern const Color Navy;                        // RGB: (0, 0, 128)
        AZCORE_API extern const Color Yellow;                      // RGB: (255, 255, 0)
        AZCORE_API extern const Color Orange;                      // RGB: (255, 165, 0)
        AZCORE_API extern const Color Olive;                       // RGB: (128, 128, 0)
        AZCORE_API extern const Color Purple;                      // RGB: (128, 0, 128)
        AZCORE_API extern const Color Fuchsia;                     // RGB: (255, 0, 255)
        AZCORE_API extern const Color Teal;                        // RGB: (0, 128, 128)
        AZCORE_API extern const Color Aqua;                        // RGB: (0, 255, 255)
        // CSS3 colors                         
        // Reds                                         
        AZCORE_API extern const Color IndianRed;                   // RGB: (205, 92, 92)
        AZCORE_API extern const Color LightCoral;                  // RGB: (240, 128, 128)
        AZCORE_API extern const Color Salmon;                      // RGB: (250, 128, 114)
        AZCORE_API extern const Color DarkSalmon;                  // RGB: (233, 150, 122)
        AZCORE_API extern const Color LightSalmon;                 // RGB: (255, 160, 122)
        AZCORE_API extern const Color Crimson;                     // RGB: (220, 20, 60)
        AZCORE_API extern const Color FireBrick;                   // RGB: (178, 34, 34)
        AZCORE_API extern const Color DarkRed;                     // RGB: (139, 0, 0)
        // Pinks                                        
        AZCORE_API extern const Color Pink;                        // RGB: (255, 192, 203)
        AZCORE_API extern const Color LightPink;                   // RGB: (255, 182, 193)
        AZCORE_API extern const Color HotPink;                     // RGB: (255, 105, 180)
        AZCORE_API extern const Color DeepPink;                    // RGB: (255, 20, 147)
        AZCORE_API extern const Color MediumVioletRed;             // RGB: (199, 21, 133)
        AZCORE_API extern const Color PaleVioletRed;               // RGB: (219, 112, 147)
        // Oranges                                      
        AZCORE_API extern const Color Coral;                       // RGB: (255, 127, 80)
        AZCORE_API extern const Color Tomato;                      // RGB: (255, 99, 71)
        AZCORE_API extern const Color OrangeRed;                   // RGB: (255, 69, 0)
        AZCORE_API extern const Color DarkOrange;                  // RGB: (255, 140, 0)
        // Yellows                                      
        AZCORE_API extern const Color Gold;                        // RGB: (255, 215, 0)
        AZCORE_API extern const Color LightYellow;                 // RGB: (255, 255, 224)
        AZCORE_API extern const Color LemonChiffon;                // RGB: (255, 250, 205)
        AZCORE_API extern const Color LightGoldenrodYellow;        // RGB: (250, 250, 210)
        AZCORE_API extern const Color PapayaWhip;                  // RGB: (255, 239, 213)
        AZCORE_API extern const Color Moccasin;                    // RGB: (255, 228, 181)
        AZCORE_API extern const Color PeachPuff;                   // RGB: (255, 218, 185)
        AZCORE_API extern const Color PaleGoldenrod;               // RGB: (238, 232, 170)
        AZCORE_API extern const Color Khaki;                       // RGB: (240, 230, 140)
        AZCORE_API extern const Color DarkKhaki;                   // RGB: (189, 183, 107)
        // Purples                                      
        AZCORE_API extern const Color Lavender;                    // RGB: (230, 230, 250)
        AZCORE_API extern const Color Thistle;                     // RGB: (216, 191, 216)
        AZCORE_API extern const Color Plum;                        // RGB: (221, 160, 221)
        AZCORE_API extern const Color Violet;                      // RGB: (238, 130, 238)
        AZCORE_API extern const Color Orchid;                      // RGB: (218, 112, 214)
        AZCORE_API extern const Color Magenta;                     // RGB: (255, 0, 255)
        AZCORE_API extern const Color MediumOrchid;                // RGB: (186, 85, 211)
        AZCORE_API extern const Color MediumPurple;                // RGB: (147, 112, 219)
        AZCORE_API extern const Color BlueViolet;                  // RGB: (138, 43, 226)
        AZCORE_API extern const Color DarkViolet;                  // RGB: (148, 0, 211)
        AZCORE_API extern const Color DarkOrchid;                  // RGB: (153, 50, 204)
        AZCORE_API extern const Color DarkMagenta;                 // RGB: (139, 0, 139)
        AZCORE_API extern const Color RebeccaPurple;               // RGB: (102, 51, 153)
        AZCORE_API extern const Color Indigo;                      // RGB: (75, 0, 130)
        AZCORE_API extern const Color MediumSlateBlue;             // RGB: (123, 104, 238)
        AZCORE_API extern const Color SlateBlue;                   // RGB: (106, 90, 205)
        AZCORE_API extern const Color DarkSlateBlue;               // RGB: (72, 61, 139)
        // Greens                                       
        AZCORE_API extern const Color GreenYellow;                 // RGB: (173, 255, 47)
        AZCORE_API extern const Color Chartreuse;                  // RGB: (127, 255, 0)
        AZCORE_API extern const Color LawnGreen;                   // RGB: (124, 252, 0)
        AZCORE_API extern const Color LimeGreen;                   // RGB: (50, 205, 50)
        AZCORE_API extern const Color PaleGreen;                   // RGB: (152, 251, 152)
        AZCORE_API extern const Color LightGreen;                  // RGB: (144, 238, 144)
        AZCORE_API extern const Color MediumSpringGreen;           // RGB: (0, 250, 154)
        AZCORE_API extern const Color SpringGreen;                 // RGB: (0, 255, 127)
        AZCORE_API extern const Color MediumSeaGreen;              // RGB: (60, 179, 113)
        AZCORE_API extern const Color SeaGreen;                    // RGB: (46, 139, 87)
        AZCORE_API extern const Color ForestGreen;                 // RGB: (34, 139, 34)
        AZCORE_API extern const Color DarkGreen;                   // RGB: (0, 100, 0)
        AZCORE_API extern const Color YellowGreen;                 // RGB: (154, 205, 50)
        AZCORE_API extern const Color OliveDrab;                   // RGB: (107, 142, 35)
        AZCORE_API extern const Color DarkOliveGreen;              // RGB: (85, 107, 47)
        AZCORE_API extern const Color MediumAquamarine;            // RGB: (102, 205, 170)
        AZCORE_API extern const Color DarkSeaGreen;                // RGB: (143, 188, 143)
        AZCORE_API extern const Color LightSeaGreen;               // RGB: (32, 178, 170)
        AZCORE_API extern const Color DarkCyan;                    // RGB: (0, 139, 139)
        // Blues                                        
        AZCORE_API extern const Color Cyan;                        // RGB: (0, 255, 255)
        AZCORE_API extern const Color LightCyan;                   // RGB: (224, 255, 255)
        AZCORE_API extern const Color PaleTurquoise;               // RGB: (175, 238, 238)
        AZCORE_API extern const Color Aquamarine;                  // RGB: (127, 255, 212)
        AZCORE_API extern const Color Turquoise;                   // RGB: (64, 224, 208)
        AZCORE_API extern const Color MediumTurquoise;             // RGB: (72, 209, 204)
        AZCORE_API extern const Color DarkTurquoise;               // RGB: (0, 206, 209)
        AZCORE_API extern const Color CadetBlue;                   // RGB: (95, 158, 160)
        AZCORE_API extern const Color SteelBlue;                   // RGB: (70, 130, 180)
        AZCORE_API extern const Color LightSteelBlue;              // RGB: (176, 196, 222)
        AZCORE_API extern const Color PowderBlue;                  // RGB: (176, 224, 230)
        AZCORE_API extern const Color LightBlue;                   // RGB: (173, 216, 230)
        AZCORE_API extern const Color SkyBlue;                     // RGB: (135, 206, 235)
        AZCORE_API extern const Color LightSkyBlue;                // RGB: (135, 206, 250)
        AZCORE_API extern const Color DeepSkyBlue;                 // RGB: (0, 191, 255)
        AZCORE_API extern const Color DodgerBlue;                  // RGB: (30, 144, 255)
        AZCORE_API extern const Color CornflowerBlue;              // RGB: (100, 149, 237)
        AZCORE_API extern const Color RoyalBlue;                   // RGB: (65, 105, 225)
        AZCORE_API extern const Color MediumBlue;                  // RGB: (0, 0, 205)
        AZCORE_API extern const Color DarkBlue;                    // RGB: (0, 0, 139)
        AZCORE_API extern const Color MidnightBlue;                // RGB: (25, 25, 112)
        // Browns                                       
        AZCORE_API extern const Color Cornsilk;                    // RGB: (255, 248, 220)
        AZCORE_API extern const Color BlanchedAlmond;              // RGB: (255, 235, 205)
        AZCORE_API extern const Color Bisque;                      // RGB: (255, 228, 196)
        AZCORE_API extern const Color NavajoWhite;                 // RGB: (255, 222, 173)
        AZCORE_API extern const Color Wheat;                       // RGB: (245, 222, 179)
        AZCORE_API extern const Color BurlyWood;                   // RGB: (222, 184, 135)
        AZCORE_API extern const Color Tan;                         // RGB: (210, 180, 140)
        AZCORE_API extern const Color RosyBrown;                   // RGB: (188, 143, 143)
        AZCORE_API extern const Color SandyBrown;                  // RGB: (244, 164, 96)
        AZCORE_API extern const Color Goldenrod;                   // RGB: (218, 165, 32)
        AZCORE_API extern const Color DarkGoldenrod;               // RGB: (184, 134, 11)
        AZCORE_API extern const Color Peru;                        // RGB: (205, 133, 63)
        AZCORE_API extern const Color Chocolate;                   // RGB: (210, 105, 30)
        AZCORE_API extern const Color SaddleBrown;                 // RGB: (139, 69, 19)
        AZCORE_API extern const Color Sienna;                      // RGB: (160, 82, 45)
        AZCORE_API extern const Color Brown;                       // RGB: (165, 42, 42)
        // Whites
        AZCORE_API extern const Color Snow;                        // RGB: (255, 250, 250)
        AZCORE_API extern const Color Honeydew;                    // RGB: (240, 255, 240)
        AZCORE_API extern const Color MintCream;                   // RGB: (245, 255, 250)
        AZCORE_API extern const Color Azure;                       // RGB: (240, 255, 255)
        AZCORE_API extern const Color AliceBlue;                   // RGB: (240, 248, 255)
        AZCORE_API extern const Color GhostWhite;                  // RGB: (248, 248, 255)
        AZCORE_API extern const Color WhiteSmoke;                  // RGB: (245, 245, 245)
        AZCORE_API extern const Color Seashell;                    // RGB: (255, 245, 238)
        AZCORE_API extern const Color Beige;                       // RGB: (245, 245, 220)
        AZCORE_API extern const Color OldLace;                     // RGB: (253, 245, 230)
        AZCORE_API extern const Color FloralWhite;                 // RGB: (255, 250, 240)
        AZCORE_API extern const Color Ivory;                       // RGB: (255, 255, 240)
        AZCORE_API extern const Color AntiqueWhite;                // RGB: (250, 235, 215)
        AZCORE_API extern const Color Linen;                       // RGB: (250, 240, 230)
        AZCORE_API extern const Color LavenderBlush;               // RGB: (255, 240, 245)
        AZCORE_API extern const Color MistyRose;                   // RGB: (255, 228, 225)
        // Grays                                        
        AZCORE_API extern const Color Gainsboro;                   // RGB: (220, 220, 220)
        AZCORE_API extern const Color LightGray;                   // RGB: (211, 211, 211)
        AZCORE_API extern const Color LightGrey;                   // RGB: (211, 211, 211)
        AZCORE_API extern const Color DarkGray;                    // RGB: (169, 169, 169)
        AZCORE_API extern const Color DarkGrey;                    // RGB: (169, 169, 169)
        AZCORE_API extern const Color Grey;                        // RGB: (128, 128, 128)
        AZCORE_API extern const Color DimGray;                     // RGB: (105, 105, 105)
        AZCORE_API extern const Color DimGrey;                     // RGB: (105, 105, 105)
        AZCORE_API extern const Color LightSlateGray;              // RGB: (119, 136, 153)
        AZCORE_API extern const Color LightSlateGrey;              // RGB: (119, 136, 153)
        AZCORE_API extern const Color SlateGray;                   // RGB: (112, 128, 144)
        AZCORE_API extern const Color SlateGrey;                   // RGB: (112, 128, 144)
        AZCORE_API extern const Color DarkSlateGray;               // RGB: (47, 79, 79)
        AZCORE_API extern const Color DarkSlateGrey;               // RGB: (47, 79, 79)
    }
}

#include <AzCore/Math/Color.inl>

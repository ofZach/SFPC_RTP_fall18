#version 150

//uniform vec2 u_mouse;
uniform sampler2DRect tex0;
#define MAX_ITEMS 100
uniform vec2 current[MAX_ITEMS];
uniform vec2 past[MAX_ITEMS];

uniform vec2 resolution;
uniform float scale;
in vec2 texCoordVarying;
uniform float time; //0~30

out vec4 outputColor;

vec3 rgb2hsb( in vec3 c ){
    vec4 K = vec4(0.0, -1.0 / 3.0, 2.0 / 3.0, -1.0);
    vec4 p = mix(vec4(c.bg, K.wz),
                 vec4(c.gb, K.xy),
                 step(c.b, c.g));
    vec4 q = mix(vec4(p.xyw, c.r),
                 vec4(c.r, p.yzx),
                 step(p.x, c.r));
    float d = q.x - min(q.w, q.y);
    float e = 1.0e-10;
    return vec3(abs(q.z + (q.w - q.y) / (6.0 * d + e)),
                d / (q.x + e),
                q.x);
}

//  Function from Iñigo Quiles
//  https://www.shadertoy.com/view/MsS3Wc
vec3 hsb2rgb( in vec3 c ){
    vec3 rgb = clamp(abs(mod(c.x*6.0+vec3(0.0,4.0,2.0),
                             6.0)-3.0)-1.0,
                     0.0,
                     1.0 );
    rgb = rgb*rgb*(3.0-2.0*rgb);
    return c.z * mix(vec3(1.0), rgb, c.y);
}
// 2D Random
float random (in vec2 st) {
    return fract(sin(dot(st.xy,
                         vec2(12.9898,78.233)))
                 * 43758.5453123);
}

// 2D Noise based on Morgan McGuire @morgan3d
// https://www.shadertoy.com/view/4dS3Wd
float noise (in vec2 st) {
    vec2 i = floor(st);
    vec2 f = fract(st);

    // Four corners in 2D of a tile
    float a = random(i);
    float b = random(i + vec2(1.0, 0.0));
    float c = random(i + vec2(0.0, 1.0));
    float d = random(i + vec2(1.0, 1.0));

    // Smooth Interpolation

    // Cubic Hermine Curve.  Same as SmoothStep()
    vec2 u = f*f*(3.0-2.0*f);
    // u = smoothstep(0.,1.,f);

    // Mix 4 coorners percentages
    return mix(a, b, u.x) +
    (c - a)* u.y * (1.0 - u.x) +
    (d - b) * u.x * u.y;
}
float mod289(float x){return x - floor(x * (1.0 / 289.0)) * 289.0;}
vec4 mod289(vec4 x){return x - floor(x * (1.0 / 289.0)) * 289.0;}
vec4 perm(vec4 x){return mod289(((x * 34.0) + 1.0) * x);}

float noise(vec3 p){
    vec3 a = floor(p);
    vec3 d = p - a;
    d = d * d * (3.0 - 2.0 * d);
    
    vec4 b = a.xxyy + vec4(0.0, 1.0, 0.0, 1.0);
    vec4 k1 = perm(b.xyxy);
    vec4 k2 = perm(k1.xyxy + b.zzww);
    
    vec4 c = k2 + a.zzzz;
    vec4 k3 = perm(c);
    vec4 k4 = perm(c + 1.0);
    
    vec4 o1 = fract(k3 * (1.0 / 41.0));
    vec4 o2 = fract(k4 * (1.0 / 41.0));
    
    vec4 o3 = o2 * d.z + o1 * (1.0 - d.z);
    vec2 o4 = o3.yw * d.x + o3.xz * (1.0 - d.x);
    
    return o4.y * d.y + o4.x * (1.0 - d.y);
}

void main() {
    vec2 st = gl_FragCoord.xy;
    vec2 normst = gl_FragCoord.xy/640;
    //vec2 center = resolution/2.0;
    // Scale the coordinate system to see
    // some noise in action
    //    vec2 pos = vec2(st*7.);
    float theta = 1.0;
    // Use the noise function
    vec4 color = vec4(0., 0., 0., 1.0);
    
    for (int i =0; i<100; i+=1) {
        vec2 pos  = current[i];
        vec2 pos2 = past[i];
        vec2 vel = (pos2-pos)*0.06*scale;
        float poscolormap = max(0,1-0.01*length(st-pos.xy));
        color.r += poscolormap*vel.x;
        color.g += poscolormap*vel.y;
    }
    //    vec2 center = resolution/2.0;
    
    //    vec3 pos  = texture(data,vec2(12,time)).rgb; // x is pos,y is time
    //    vec3 pos2 = texture(data,vec2(12,mod(time+1,30))).rgb; // x is pos,y is time
    //    vec3 vel = pos2-pos;
    //    color.r += scale*(10-length(st-pos.xy));
    //    color.g += scale*(10-length(st-pos.xy));
    vec4 outc = (0.11)*color+0.9*texture(tex0,st);
    outputColor = vec4(outc.rgb,1.0);
}



#version 300 es

out vec4 FragColor;

in vec3 ourColor;
in vec2 TexCoord;
in vec3 fragmentPosition;

// texture samplers
uniform sampler2D Texture1;
uniform sampler2D Texture2;
uniform float OpacityLerp;

void main()
{
	//FragColor = mix(texture(Texture1, TexCoord), texture(Texture2, TexCoord), 0.8);
	//FragColor = mix(texture(Texture1, TexCoord), texture(Texture2, TexCoord), 0.2);
	FragColor = mix(texture(Texture1, TexCoord), texture(Texture2, TexCoord), OpacityLerp);
	//FragColor = mix(texture(Texture1, TexCoord), texture(Texture2, vec2(2.0 - TexCoord.x, 2.0 - TexCoord.y)), 0.2);
	//FragColor = mix(texture(Texture1, TexCoord), texture(Texture2, vec2(1.0 - TexCoord.x, TexCoord.y)), 0.2); // putting two textures on top of each other and mixing them with 20%
	//FragColor = texture(Texture1, TexCoord) * vec4(ourColor, 1.0); // Putting color on texture (helpful for showing damage on object)

    /*const float refractiveIndex = 1.5; // Typical value for glass
    const float reflectionStrength = 0.5; // Adjust as needed

    // Calculate view direction
    vec3 viewDir = normalize(-fragmentPosition);

    // Calculate refraction
    vec3 refractedDir = refract(viewDir, normalize(vec3(0.0, 0.0, 1.0)), refractiveIndex);

    // Calculate reflection
    vec3 reflectedDir = reflect(viewDir, normalize(vec3(0.0, 0.0, 1.0)));

    // Combine refraction and reflection
    vec3 finalColor = mix(refractedDir, reflectedDir, reflectionStrength);

    FragColor = vec4(finalColor, 1.0);*/
}
import matplotlib.pyplot as plt

# Data for types of AI
types_of_ai = {
    "Weak AI": ["Chess AI", "Personal Assistants (Siri, Alexa)"],
    "Strong AI": ["Self-driving Cars", "Hospital Operating Systems"]
}

# Data for stages of AI development
stages_of_ai = {
    "Reactive Machines": ["Deep Blue (Chess AI)"],
    "Limited Memory": ["Self-driving Cars"],
    "Theory of Mind": ["Future AI with social intelligence"],
    "Self-awareness": ["Hypothetical Future AI"]
}

# Data for advantages vs. disadvantages
advantages = ["Good at detail-oriented jobs", "Reduces time for data-heavy tasks", 
              "Saves labor and increases productivity", "Delivers consistent results", 
              "Improves customer satisfaction through personalization", 
              "24/7 availability with AI-powered virtual agents"]

disadvantages = ["Expensive", "Requires deep technical expertise", 
                 "Limited supply of qualified workers", 
                 "Reflects biases of its training data", 
                 "Lack of ability to generalize tasks", 
                 "Eliminates human jobs"]

# Data for AI impact in different sectors
sectors = ["Healthcare", "Cybersecurity", "Transportation", "E-commerce", "Employment"]
impact_levels = [8, 7, 6, 9, 5]  # Arbitrary impact levels for visualization

# Plotting the data
fig, ax = plt.subplots(3, 1, figsize=(10, 15))

# Types of AI
ax[0].barh(list(types_of_ai.keys()), [len(v) for v in types_of_ai.values()])
ax[0].set_title("Types of Artificial Intelligence")
ax[0].set_xlabel("Number of Examples")
ax[0].set_ylabel("Type of AI")

# Advantages vs. Disadvantages of AI
ax[1].barh(["Advantages", "Disadvantages"], [len(advantages), len(disadvantages)], color=['green', 'red'])
ax[1].set_title("Advantages vs. Disadvantages of AI")
ax[1].set_xlabel("Number of Points")
ax[1].set_ylabel("Category")

# AI Impact in Different Sectors
ax[2].bar(sectors, impact_levels, color='blue')
ax[2].set_title("AI's Impact in Different Sectors")
ax[2].set_xlabel("Sector")
ax[2].set_ylabel("Impact Level (Arbitrary Scale)")

# Adjust layout and show the plots
plt.tight_layout()
plt.show()
